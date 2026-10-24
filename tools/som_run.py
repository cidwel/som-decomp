#!/usr/bin/env python3
"""Stage 1 launcher: build the hybrid Secret of Mana ROM from src/ + your ROM and play it.

    tools/som_run.py --rom "/path/to/Secret of Mana (USA).sfc"            # play
    tools/som_run.py --rom ... --check                                    # no window

What it does:
  1. Hashes src/ (plus manifest files outside src/, the build tool closure and the ca65/ld65 binaries) into a source key.
  2. Assembles src/ with ca65/ld65 into a ROM-free partial image, cached under
     $XDG_CACHE_HOME/som-run (default ~/.cache/som-run) by that key.  Reruns are instant.
  3. Fills the bytes src/ does not cover from YOUR ROM, requires every source byte to equal
     your ROM and the final sha256 to equal the original, and caches the hybrid image.
  4. Launches an installed open-source libretro core: RetroArch (flatpak or native) with a
     generated override config, or the bundled SDL2 frontend (tools/som_sdl_launcher.c).

The result is a HYBRID: the emulator is third party and a part of the ROM comes from you.
Nothing is written inside the repository and no ROM data is distributed.
"""
import argparse
import hashlib
import json
import os
import pathlib
import shutil
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor

HERE = pathlib.Path(__file__).resolve().parent
ROOT = HERE.parent
sys.path.insert(0, str(HERE))

import som_assemble_rom as sar  # noqa: E402

FLATPAK_ID = 'org.libretro.RetroArch'
AUDIO_LATENCY_MS = '64'
CORE_NAMES = ['snes9x', 'bsnes']  # snes9x first: it is the core the stage 0 runs used most
CORE_DIRS = [
    pathlib.Path.home() / '.var/app' / FLATPAK_ID / 'config/retroarch/cores',
    pathlib.Path.home() / '.config/retroarch/cores',
    pathlib.Path('/usr/lib/libretro'), pathlib.Path('/usr/lib64/libretro'),
    pathlib.Path('/usr/lib/x86_64-linux-gnu/libretro'), pathlib.Path('/usr/local/lib/libretro'),
]


CONFIG_PATH = pathlib.Path(os.environ.get('XDG_CONFIG_HOME') or pathlib.Path.home() / '.config') \
    / 'som-decomp' / 'config.toml'


def load_config():
    """Optional user config; only paths and preferences, never ROM data."""
    try:
        import tomllib
        return tomllib.loads(CONFIG_PATH.read_text())
    except (OSError, ImportError, ValueError):
        return {}


def save_config_rom(rom):
    CONFIG_PATH.parent.mkdir(parents=True, exist_ok=True)
    text = CONFIG_PATH.read_text() if CONFIG_PATH.exists() else ''
    lines = [l for l in text.splitlines() if not l.startswith('rom ')]
    lines.insert(0, 'rom = "%s"' % str(rom).replace('\\', '\\\\').replace('"', '\\"'))
    CONFIG_PATH.write_text('\n'.join(lines) + '\n')
    say('saved ROM path to %s' % CONFIG_PATH)


def cache_root(arg):
    base = os.environ.get('XDG_CACHE_HOME') or str(pathlib.Path.home() / '.cache')
    return pathlib.Path(arg or os.environ.get('SOM_CACHE') or pathlib.Path(base) / 'som-run')


def say(message):
    print('[som-run] ' + message, flush=True)


def die(message):
    if not sys.stdout.isatty() and shutil.which('notify-send'):  # started from a menu entry: no terminal to read
        subprocess.run(['notify-send', '-a', 'som-run', 'Secret of Mana launcher', message[:400]],
                       capture_output=True)
    sys.exit('[som-run] ERROR: ' + message)


# ---------------------------------------------------------------- source key

BUILD_SEEDS = ['build_recovered_rom.py', 'som_assemble_rom.py']


def _file_sha(path):
    h = hashlib.sha256()
    with open(path, 'rb') as f:
        for chunk in iter(lambda: f.read(1 << 20), b''):
            h.update(chunk)
    return h.digest()


def build_tool_closure(tools_dir=None, seeds=None):
    """Seed tools plus every tools/ module they import, transitively (static AST walk, lazy imports included)."""
    import ast
    tools_dir = pathlib.Path(tools_dir or HERE)
    pending, seen = list(seeds or BUILD_SEEDS), set()
    while pending:
        name = pending.pop()
        if name in seen:
            continue
        seen.add(name)
        tree = ast.parse((tools_dir / name).read_text())
        for node in ast.walk(tree):
            mods = [a.name for a in node.names] if isinstance(node, ast.Import) else \
                [node.module] if isinstance(node, ast.ImportFrom) and node.module and not node.level else []
            for mod in mods:
                candidate = mod.split('.')[0] + '.py'
                if (tools_dir / candidate).is_file():
                    pending.append(candidate)
    return sorted(seen)


def manifest_external_files(root=None):
    """Files the build reads that the manifest points at outside src/ (sources and compression plans)."""
    root = pathlib.Path(root or ROOT)
    manifest = json.loads((root / 'src/manifest.json').read_text())
    paths = {b['source'] for b in manifest['blocks']}
    paths |= {r['plan'] for r in manifest.get('decoded_resources', []) if 'plan' in r}
    return sorted(p for p in paths if not p.startswith('src/'))


def source_key(cache, ca65, ld65=None, root=None, tools_dir=None):
    """Content hash of everything the build reads: src/, manifest-listed files outside src/, the
    build tool closure and the ca65/ld65 binaries; a stat signature memo makes reruns ~1 s."""
    root = pathlib.Path(root or ROOT)
    tools_dir = pathlib.Path(tools_dir or HERE)
    files, sig = [], hashlib.sha256()
    for base, _, names in os.walk(root / 'src'):
        for name in names:
            files.append(os.path.join(base, name))
    files.sort()
    extra = [str(root / p) for p in manifest_external_files(root)]
    tools = [str(tools_dir / n) for n in build_tool_closure(tools_dir)]
    binaries = [str(pathlib.Path(b).resolve()) for b in (ca65, ld65) if b]
    for path in files + extra + tools + binaries:
        st = os.stat(path)
        sig.update(('%s\0%d\0%d\n' % (path, st.st_size, st.st_mtime_ns)).encode())
    version = ''
    for binary in binaries:
        out = subprocess.run([binary, '--version'], capture_output=True, text=True)
        version += (out.stdout + out.stderr).strip() + '\n'
    sig.update(version.encode())
    memo_path = cache / 'source-key-memo.json'
    try:
        memo = json.loads(memo_path.read_text())
    except (OSError, ValueError):
        memo = {}
    stat_sig = sig.hexdigest()
    if stat_sig in memo:
        return memo[stat_sig], len(files), True
    with ThreadPoolExecutor(max_workers=os.cpu_count() or 4) as pool:
        digests = list(pool.map(_file_sha, files + extra + tools + binaries, chunksize=256))
    h = hashlib.sha256(version.encode())
    for path, digest in zip(files + extra + tools + binaries, digests):
        if path in binaries:
            label = 'bin:' + os.path.basename(path)
        elif path in tools:
            label = 'tool:' + os.path.basename(path)
        else:
            label = os.path.relpath(path, root)
        h.update(label.encode() + b'\0' + digest)
    key = h.hexdigest()[:24]
    memo_path.write_text(json.dumps({stat_sig: key}))
    return key, len(files), False


# ---------------------------------------------------------------- build / compose

def find_cc65(args):
    ca65, ld65 = args.ca65, args.ld65
    if not ca65.exists():
        ca65 = shutil.which('ca65') and pathlib.Path(shutil.which('ca65')) or ca65
    if not ld65.exists():
        ld65 = shutil.which('ld65') and pathlib.Path(shutil.which('ld65')) or ld65
    if not (ca65.exists() and ld65.exists()):
        die('ca65/ld65 (cc65) not found; pass --ca65/--ld65 or put them in PATH '
            '(default looked at %s)' % sar.CC65_BIN)
    return ca65, ld65


def ensure_partial(cache, key, ca65, ld65, rebuild):
    build = cache / 'build' / key
    if (build / 'rom.partial.bin').exists() and (build / 'rom.known-mask.bin').exists() and not rebuild:
        say('assembled source image cached (%s)' % build)
        return build
    import build_recovered_rom as brr
    say('assembling src/ with ca65/ld65 (about 3 min, one time per source change)...')
    tmp = cache / 'build' / (key + '.tmp')
    shutil.rmtree(tmp, ignore_errors=True)
    start = time.time()
    try:
        brr.build(tmp, str(ca65), str(ld65))
    except ValueError as error:
        shutil.rmtree(tmp, ignore_errors=True)
        die('source build failed: %s' % error)
    shutil.rmtree(build, ignore_errors=True)
    tmp.rename(build)
    say('assembled in %.0f s' % (time.time() - start))
    return build


def ensure_hybrid(cache, key, build, rom_path, expected, rebuild):
    user_rom, stripped = sar.load_user_rom(rom_path)
    rom_sha = hashlib.sha256(user_rom).hexdigest()
    if rom_sha != expected:
        die('your ROM has sha256 %s but the original USA ROM is %s; this is a different '
            'dump, region or hack' % (rom_sha, expected))
    out = cache / 'hybrid' / (key + '-' + rom_sha[:8])
    hybrid, report = out / 'som_hybrid.sfc', out / 'report.json'
    if hybrid.exists() and report.exists() and not rebuild:
        if hashlib.sha256(hybrid.read_bytes()).hexdigest() == expected:
            say('hybrid ROM cached and sha256 verified: %s' % hybrid)
            return hybrid, json.loads(report.read_text()), user_rom, stripped
        say('cached hybrid failed its hash check; recomposing')
    partial = (build / 'rom.partial.bin').read_bytes()
    mask = (build / 'rom.known-mask.bin').read_bytes()
    image, mismatches = sar.compose(partial, mask, user_rom)
    if mismatches:
        die('%d source-built bytes differ from your ROM (first at 0x%06X); refusing to continue'
            % (len(mismatches), mismatches[0]))
    sha = hashlib.sha256(image).hexdigest()
    if sha != expected:
        die('hybrid sha256 %s != expected %s' % (sha, expected))
    gaps = sar.gap_list(mask)
    src_bytes = sum(mask)
    rep = dict(sha256=sha, sha256_matches_original=True, bytes_from_source=src_bytes,
               bytes_from_user_rom=sar.ROM_SIZE - src_bytes,
               percent_from_source=round(100 * src_bytes / sar.ROM_SIZE, 3), gaps=len(gaps),
               gap_bytes_by_bank=sar.bank_summary(gaps), source_bytes_mismatching=0,
               source_key=key, user_rom_copier_header_stripped=stripped, hybrid=True)
    out.mkdir(parents=True, exist_ok=True)
    hybrid.write_bytes(image)
    report.write_text(json.dumps(rep, indent=2) + '\n')
    say('hybrid ROM composed: %s' % hybrid)
    return hybrid, rep, user_rom, stripped


def snes_address(offset):
    """File offset of the 3 MiB HiROM image -> bank:offset in the C0-EF mirror."""
    return '%02X:%04X' % (0xC0 + (offset >> 16), offset & 0xFFFF)


def format_gaps(gaps):
    lines = ['  %s-%s  file 0x%06X-0x%06X  %7d bytes' % (
        snes_address(start), snes_address(start + size - 1), start, start + size - 1, size)
        for start, size in gaps]
    banks = ', '.join('%s %s' % (b, format(n, ',')) for b, n in sorted(sar.bank_summary(gaps).items()))
    return '\n'.join(lines), banks


def source_gaps(build):
    mask = (build / 'rom.known-mask.bin').read_bytes()
    return mask, sar.gap_list(mask)


def refuse_for_gaps(gaps, cache, could_fill):
    listing, banks = format_gaps(gaps)
    total = sum(size for _, size in gaps)
    (cache / 'gaps.txt').write_text(listing + '\n')
    print(listing)
    say('src/ does not cover the whole ROM: %s bytes in %d gaps (%s); list also in %s'
        % (format(total, ','), len(gaps), banks, cache / 'gaps.txt'))
    if could_fill:
        die('--no-user-rom refused: there is no way to build the ROM from src/ alone yet. Use '
            '--fill-from-rom with your own ROM, or close the gaps above.')
    die('refusing to launch: src/ alone cannot produce the ROM yet and no ROM was given for '
        '--fill-from-rom (--rom PATH, $SOM_ROM or "rom = ..." in %s).' % CONFIG_PATH)


def ensure_source_only(cache, key, build, expected, rebuild):
    """Image built from src/ alone; only possible once there is no gap.  Verified by sha256 and SNES checksum fields."""
    mask, gaps = source_gaps(build)
    if gaps:
        return None, gaps
    partial = (build / 'rom.partial.bin').read_bytes()
    sha = hashlib.sha256(partial).hexdigest()
    if sha != expected:
        die('src/ covers every ROM byte but the assembled image has sha256 %s, expected %s; '
            'refusing to launch' % (sha, expected))
    out = cache / 'source-only' / key
    problems = sar.internal_checksum_problems(partial)
    if problems:
        die('source-only image has a bad SNES internal checksum: %s; refusing to launch' % '; '.join(problems))
    out.mkdir(parents=True, exist_ok=True)
    image = out / 'som_source.sfc'
    image.write_bytes(partial)
    (out / 'report.json').write_text(json.dumps(dict(
        sha256=sha, sha256_matches_original=True, internal_checksum_valid=True, bytes_from_source=len(partial),
        bytes_from_user_rom=0, gaps=0, source_key=key, source_only=True), indent=2) + '\n')
    say('source-only ROM built from src/ and sha256 verified (no ROM used): %s' % image)
    return image, []


# ---------------------------------------------------------------- frontends

def find_cores(extra):
    found = {}
    dirs = ([pathlib.Path(extra)] if extra else []) + \
        ([pathlib.Path(os.environ['SOM_CORE_DIR'])] if os.environ.get('SOM_CORE_DIR') else []) + CORE_DIRS
    for name in CORE_NAMES:
        for d in dirs:
            if (d / (name + '_libretro.so')).exists():
                found[name] = d / (name + '_libretro.so')
                break
    return found


def flatpak_retroarch():
    if not shutil.which('flatpak'):
        return False
    return subprocess.run(['flatpak', 'info', FLATPAK_ID], capture_output=True).returncode == 0


def sdl_available():
    if not (shutil.which('gcc') and shutil.which('pkg-config')):
        return False
    return subprocess.run(['pkg-config', '--exists', 'sdl2']).returncode == 0


def build_sdl_launcher(cache):
    src = HERE / 'som_sdl_launcher.c'
    binary = cache / 'bin' / 'som_sdl_launcher'
    binary.parent.mkdir(parents=True, exist_ok=True)
    if not binary.exists() or binary.stat().st_mtime < src.stat().st_mtime:
        flags = subprocess.run(['pkg-config', '--cflags', '--libs', 'sdl2'], capture_output=True,
                               text=True, check=True).stdout.split()
        subprocess.run(['gcc', '-O2', '-Wall', '-o', str(binary), str(src)] + flags + ['-ldl'], check=True)
        say('built SDL2 frontend: %s' % binary)
    return binary


RETROARCH_KEYS = {  # SNES pad -> keyboard (same layout as the SDL frontend)
    'b': 'z', 'a': 'x', 'y': 'a', 'x': 's', 'l': 'q', 'r': 'w', 'start': 'enter',
    'select': 'rshift', 'up': 'up', 'down': 'down', 'left': 'left', 'right': 'right'}
# RETRO_DEVICE_ID_JOYPAD order, used by the explicit core remap files.
RETROPAD_IDS = ['b', 'y', 'select', 'start', 'up', 'down', 'left', 'right', 'a', 'x', 'l', 'r']
REMAP_CORES = {'snes9x': 'Snes9x', 'bsnes': 'bsnes'}  # core name -> RetroArch remap directory


def write_remaps(root):
    """Explicit identity core remaps (RetroPad id -> SNES button) so the mapping is stated, not implied."""
    for core in REMAP_CORES.values():
        directory = root / core
        directory.mkdir(parents=True, exist_ok=True)
        text = 'input_libretro_device_p1 = "1"\n'
        text += ''.join('input_player1_btn_%s = "%d"\n' % (name, i) for i, name in enumerate(RETROPAD_IDS))
        text += ''.join('input_player1_btn_%s = "-1"\n' % name for name in ('l2', 'r2', 'l3', 'r3'))
        (directory / (core + '.rmp')).write_text(text)


def write_retroarch_config(cache, fullscreen):
    saves = cache / 'saves'
    states = cache / 'states'
    remaps = cache / 'retroarch' / 'remaps'
    for d in (saves, states, cache / 'retroarch'):
        d.mkdir(parents=True, exist_ok=True)
    write_remaps(remaps)
    lines = {
        'video_fullscreen': str(bool(fullscreen)).lower(),
        'savefile_directory': str(saves), 'savestate_directory': str(states),
        'input_remapping_directory': str(remaps),
        'config_save_on_exit': 'false', 'savestate_auto_save': 'false',
        'savestate_auto_load': 'false', 'input_autodetect_enable': 'true',
        'input_player1_analog_dpad_mode': '1', 'pause_nonactive': 'false',
        'video_aspect_ratio_auto': 'true', 'video_scale_integer': 'false',
        'menu_show_start_screen': 'false', 'video_windowed_fullscreen': 'true', 'video_vsync': 'false',
        'video_scale': '3', 'video_window_save_positions': 'false',
        # Audio: the core emits 32040 Hz; Pulse/PipeWire runs at 48000 Hz, so resample here once.
        'audio_sync': 'true', 'audio_latency': AUDIO_LATENCY_MS, 'audio_out_rate': '48000',
        'audio_enable': 'true', 'audio_mute_enable': 'false', 'audio_rate_control': 'true',
        'audio_rate_control_delta': '0.005', 'audio_max_timing_skew': '0.05',
        'audio_resampler': 'sinc', 'audio_volume': '0.0'}
    lines.update({'input_player1_' + k: v for k, v in RETROARCH_KEYS.items()})
    path = cache / 'retroarch' / 'som-run.cfg'
    path.write_text(''.join('%s = "%s"\n' % kv for kv in lines.items()))
    return path


def launch_command(args, cache, rom, core_path, cores):
    """Return (argv, description) for the chosen frontend, or die with a clear message."""
    frontend = args.frontend
    have_fp, have_native = flatpak_retroarch(), bool(shutil.which('retroarch'))
    have_sdl = sdl_available()
    if frontend == 'auto':
        frontend = 'retroarch' if (have_fp or have_native) else 'sdl' if have_sdl else None
    if frontend is None:
        die('no frontend found. Install the RetroArch flatpak ("flatpak install flathub '
            '%s") and its snes9x/bsnes cores, or install SDL2 development files and gcc for the '
            'bundled SDL2 frontend (pkg-config sdl2 failed).' % FLATPAK_ID)
    if frontend == 'retroarch':
        if not (have_fp or have_native):
            die('RetroArch not found: install the flatpak %s or a native retroarch' % FLATPAK_ID)
        cfg = write_retroarch_config(cache, args.fullscreen)
        if have_fp:
            argv = ['flatpak', 'run', '--filesystem=' + str(cache), FLATPAK_ID]
        else:
            argv = ['retroarch']
        argv += ['--verbose', '--appendconfig', str(cfg), '-L', str(core_path), str(rom)]
        return argv, 'RetroArch (%s) + %s' % ('flatpak' if have_fp else 'native', core_path.name)
    if not have_sdl:
        die('SDL2 frontend requested but "pkg-config --exists sdl2" or gcc is unavailable')
    binary = build_sdl_launcher(cache)
    argv = [str(binary), '--core', str(core_path), '--rom', str(rom), '--save-dir', str(cache / 'saves')]
    (cache / 'saves').mkdir(parents=True, exist_ok=True)
    if args.fullscreen:
        argv.append('--fullscreen')
    return argv, 'bundled SDL2 frontend + %s' % core_path.name


def has_display():
    return bool(os.environ.get('DISPLAY') or os.environ.get('WAYLAND_DISPLAY'))


def run_frontend(argv, args, cache):
    logs = cache / 'logs'
    logs.mkdir(parents=True, exist_ok=True)
    log = logs / time.strftime('run-%Y%m%d-%H%M%S.log')
    if args.xvfb:
        if not shutil.which('xvfb-run'):
            die('--xvfb needs xvfb-run (package xvfb)')
        argv = ['xvfb-run', '-a', '-s', '-screen 0 1280x720x24'] + argv
    elif not has_display():
        die('no DISPLAY/WAYLAND_DISPLAY: start from a graphical session, or use --xvfb for a '
            'virtual display (testing) or --check for the headless verification')
    say('launching: ' + ' '.join(argv))
    say('log: %s' % log)
    with open(log, 'w') as out:
        out.write('# ' + ' '.join(argv) + '\n')
        out.flush()
        proc = subprocess.Popen(argv, stdout=out, stderr=subprocess.STDOUT, start_new_session=True)
        try:
            code = proc.wait(timeout=args.test_seconds or None)
        except subprocess.TimeoutExpired:
            say('--test-seconds %s elapsed; stopping the frontend (it ran that long)' % args.test_seconds)
            import signal
            if argv[0] == 'flatpak' or FLATPAK_ID in argv:
                subprocess.run(['flatpak', 'kill', FLATPAK_ID], capture_output=True)
            os.killpg(proc.pid, signal.SIGTERM)
            try:
                proc.wait(timeout=10)
            except subprocess.TimeoutExpired:
                os.killpg(proc.pid, signal.SIGKILL)
            code = 'timeout-stopped'
    tail = log.read_text().splitlines()[-12:]
    say('frontend exit: %s; last log lines:' % code)
    for line in tail:
        print('    ' + line)
    return code


# ---------------------------------------------------------------- check mode

def run_check(args, cache, hybrid, rom_path, user_rom, stripped, cores):
    import som_boot_smoke as smoke
    if not cores:
        die('--check needs a libretro core (snes9x_libretro.so or bsnes_libretro.so); searched: %s'
            % ', '.join(str(d) for d in CORE_DIRS))
    for name in list(smoke.CORES):
        if name in cores:
            smoke.CORES[name] = cores[name]
        else:
            del smoke.CORES[name]
    reference = rom_path
    if stripped:
        reference = cache / 'reference_headerless.sfc'
        reference.write_bytes(user_rom)
    argv = ['som_boot_smoke.py', '--reference-rom', str(reference), '--hybrid-rom', str(hybrid),
            '--frames', str(args.frames), '--scratch', str(cache / 'smoke'), '--tag', 'check',
            '--cores'] + list(cores)
    if args.input_script:
        argv += ['--input-script', str(args.input_script)]
    sys.argv = argv
    say('boot smoke: %d frames, cores %s, reference vs hybrid (headless)' % (args.frames, ', '.join(cores)))
    try:
        smoke.main()
    except SystemExit as stop:
        return 0 if stop.code in (0, None) else 1
    return 0


def run_source_only_check(args, cache, image, cores):
    """No reference ROM exists in this mode: boot the image and require real sound."""
    if not cores:
        die('--check needs a libretro core')
    name = args.core or next(iter(cores))
    argv = [sys.executable, str(HERE / 'som_audio_check.py'), '--core', name, '--core-path', str(cores[name]),
            '--hybrid-rom', str(image), '--frames', str(args.frames), '--scratch', str(cache / 'smoke')]
    return subprocess.run(argv).returncode


def main():
    parser = argparse.ArgumentParser(description=__doc__,
                                     formatter_class=argparse.RawDescriptionHelpFormatter)
    config = load_config()
    default_rom = os.environ.get('SOM_ROM') or config.get('rom')
    parser.add_argument('--rom', type=pathlib.Path,
                        default=pathlib.Path(default_rom).expanduser() if default_rom else None,
                        help='your own Secret of Mana (USA) ROM (default: $SOM_ROM, then "rom" in %s)'
                        % CONFIG_PATH)
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument('--no-user-rom', action='store_true',
                      help='build the ROM from src/ alone (no ROM is read) and verify its sha256 against '
                      'the constant in the repository; refuses to launch while any gap remains')
    mode.add_argument('--fill-from-rom', action='store_true',
                      help='fill the bytes src/ lacks from your own ROM (hybrid, needs --rom)')
    parser.add_argument('--save-config', action='store_true',
                        help='remember --rom (path only) in %s' % CONFIG_PATH)
    parser.add_argument('--check', action='store_true',
                        help='assemble + verify + headless boot smoke; no window')
    parser.add_argument('--frames', type=int, default=1800, help='--check boot smoke length')
    parser.add_argument('--input-script', type=pathlib.Path, help='--check input script (default START presses)')
    parser.add_argument('--frontend', choices=['auto', 'retroarch', 'sdl'], default=config.get('frontend', 'auto'))
    parser.add_argument('--core', choices=CORE_NAMES, default=config.get('core'), help='default: first installed of snes9x, bsnes')
    parser.add_argument('--core-dir', help='extra directory with <name>_libretro.so cores')
    parser.add_argument('--fullscreen', action='store_true', default=bool(config.get('fullscreen', False)), help='start fullscreen (default off)')
    parser.add_argument('--cache-dir', help='default: $SOM_CACHE or ~/.cache/som-run')
    parser.add_argument('--rebuild', action='store_true', help='ignore the caches')
    parser.add_argument('--prepare-only', action='store_true', help='assemble and verify, then stop')
    parser.add_argument('--xvfb', action='store_true', help='run the frontend on a virtual X display (testing)')
    parser.add_argument('--test-seconds', type=float, default=0, help='stop the frontend after N seconds (testing)')
    parser.add_argument('--ca65', type=pathlib.Path, default=sar.CC65_BIN / 'ca65')
    parser.add_argument('--ld65', type=pathlib.Path, default=sar.CC65_BIN / 'ld65')
    args = parser.parse_args()

    if args.fill_from_rom and not args.rom:
        die('--fill-from-rom needs your ROM: --rom PATH, $SOM_ROM or "rom = ..." in %s. This '
            'repository contains none.' % CONFIG_PATH)
    if args.rom and not args.rom.is_file() and not args.no_user_rom:
        die('ROM not found: %s' % args.rom)
    if args.save_config and args.rom:
        save_config_rom(args.rom.resolve())
    cache = cache_root(args.cache_dir or config.get('cache_dir'))
    if sar.inside_repo(cache):
        die('the cache must be outside the repository (it will hold ROM data): %s' % cache)
    cache.mkdir(parents=True, exist_ok=True)

    ca65, ld65 = find_cc65(args)
    key, nfiles, memo = source_key(cache, ca65, ld65)
    say('source key %s (%d src files%s)' % (key, nfiles, ', stat memo hit' if memo else ', content hashed'))
    build = ensure_partial(cache, key, ca65, ld65, args.rebuild)

    image, user_rom, stripped = None, None, 0
    if not args.fill_from_rom:  # auto and --no-user-rom: src/ alone wins as soon as it is complete
        if args.no_user_rom and args.rom:
            say('--no-user-rom: ignoring --rom, no ROM is read')
        image, gaps = ensure_source_only(cache, key, build, sar.EXPECTED_SHA256, args.rebuild)
        if image is None and (args.no_user_rom or not args.rom):
            refuse_for_gaps(gaps, cache, args.no_user_rom)
        if image is None:
            say('mode: fill-from-rom (src/ has %d gaps, %s bytes)' % (len(gaps), format(sum(g[1] for g in gaps), ',')))
        else:
            say('mode: no-user-rom (src/ covers the whole ROM)')
    else:
        say('mode: fill-from-rom (explicit)')
    if image is None:
        image, report, user_rom, stripped = ensure_hybrid(cache, key, build, args.rom, sar.EXPECTED_SHA256,
                                                          args.rebuild)
        say('sha256 %s == original; %.3f %% of bytes from src/, %d bytes (%d gaps) from your ROM'
            % (report['sha256'], report['percent_from_source'], report['bytes_from_user_rom'], report['gaps']))
    hybrid = image
    cores = find_cores(args.core_dir)
    say('cores found: %s' % (', '.join('%s=%s' % kv for kv in cores.items()) or 'none'))

    if args.check:
        if user_rom is None:
            code = run_source_only_check(args, cache, hybrid, cores)
        else:
            code = run_check(args, cache, hybrid, args.rom, user_rom, stripped, cores)
        say('CHECK ' + ('PASSED' if code == 0 else 'FAILED'))
        sys.exit(code)
    if args.prepare_only:
        return
    if not cores:
        die('no libretro SNES core found (looked for snes9x_libretro.so / bsnes_libretro.so in %s). '
            'Install them from RetroArch (Online Updater > Core Downloader) or pass --core-dir.'
            % ', '.join(str(d) for d in CORE_DIRS))
    name = args.core or next(iter(cores))
    if name not in cores:
        die('core %s not installed (found: %s)' % (name, ', '.join(cores)))
    argv, description = launch_command(args, cache, hybrid, cores[name], cores)
    say('frontend: ' + description)
    code = run_frontend(argv, args, cache)
    sys.exit(code if isinstance(code, int) else 0)


if __name__ == '__main__':
    main()
