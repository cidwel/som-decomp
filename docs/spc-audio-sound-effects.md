# Native SPC mono/stereo effect allocation and duplicate priority

`SoundEffects` reconstructs four complete bodies, with fixed mnemonic sources independently matching **428 instruction bytes**: SPC0E10..0EF5 (230 bytes, ROMC3135A), builtin selector 0EF6..0F10 (27, ROMC31440), mono allocator 0F11..0F90 (128, ROMC3145B), and duplicate/priority helper 0FCE..0FF8 (43, ROMC31518). The 61 intervening bytes at 0F91 belong to the separate parameter helper and are not counted twice. The builtin sequence selector's **32 numeric target bytes at SPC153B/ROMC31A85** are reproduced as typed `.word` constants; the three target sequences themselves remain interpreter data outside this batch.

The public setup reads each four-byte runtime table record, dispatches absent/mono/stereo pointers and retains the literal fallback for a missing first pointer. Both allocators search the native upper-RAM voice identities, preserve the priority condition, select existing/free slots and stop when saturated. The stereo search considers two complementary voice bits together, shifts the native mask, marks all pending/active flags and initializes both sequences in their original order. The mono selector follows the same native upper identities and mask fields. Complete channel initialization, sample slot four and the signed effect fade helper are reused through their reconstructed behaviors; no dependency is replaced by a no-op.

Duplicate priority is a stack protocol, not a simple false result: when an effect identity exists and B6's low nibble is zero, the helper executes two POP A instructions to remove its caller's return address, then RET to the outer caller. Consequently A retains that removed address's high byte, 0E in the stereo caller or 0F in the mono caller, while the priority-test flags stay unchanged. The readable model propagates this cancellation through the whole entry, including those exact A/flag effects. Calls with permitted priority preserve the original descending index/mask alignment, including wrapping arithmetic.

The captured comparison passed **2,304 complete original calls** across 265 PC/P states and 11 dependency hashes. It enters unpatched original 0E10 for 2,048 calls (all 256 sound selector bytes across eight mask/priority/repeat contexts) and original 0EF6 for 256 calls (all commands 10..1F). It restores the six uploaded blocks, keeps their real runtime tables and randomizes other RAM, registers, flags, DSP and ports. It compares all RAM outside six nested caller/saved-register/status stack bytes 01EA..01EF, full CPU/SP/PC and peripheral/ordered I/O state. No subsequent voice bytecode is executed, so the proof checks selection/setup and cancellation rather than waveform or note playback. The full sequencer and hardware timing remain open.

The process finished terminal exit zero; report `data/spc_audio_sound_effects.json` records 386 real priority cancellations and 1206 calls reaching channel initialization. All 428 instruction bytes and the 32 numeric bytes match, with the separate 90-byte parameter/sample dependencies also verified by their own 2,048-call capture. No added source duplicates those dependencies.

Reproduce the saved capture through the public validator:

```sh
python3 - <<'PY'
import json, sys
from pathlib import Path
sys.path.insert(0, 'tools')
import romio, spc_audio_sound_effects
report = spc_audio_sound_effects.validate(romio.load('baserom.sfc'))
Path('data/spc_audio_sound_effects.json').write_text(json.dumps(report, indent=2) + '\n')
PY
```
