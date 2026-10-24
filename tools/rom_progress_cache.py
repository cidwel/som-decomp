"""Reuse a full audited inventory only while its inputs and region data are intact."""
import ast
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CACHE = ROOT / 'data/rom_progress_audit_cache.json'
TABLES = ('monsters.json', 'weapons.json', 'armors.json', 'spells.json',
          'boss_attacks.json', 'items.json', 'hero_levels.json')


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def inventory_digest(regions):
    return hashlib.sha256(json.dumps(regions, sort_keys=True, separators=(',', ':')).encode()).hexdigest()


def inputs():
    paths = {ROOT / 'data' / name for name in TABLES}
    pending = ['rom_progress.py']
    seen = set()
    while pending:
        name = pending.pop()
        if name in seen:
            continue
        seen.add(name)
        path = ROOT / 'tools' / name
        paths.add(path)
        for node in ast.walk(ast.parse(path.read_bytes())):
            modules = ([alias.name.split('.')[0] for alias in node.names] if isinstance(node, ast.Import)
                       else [node.module.split('.')[0]] if isinstance(node, ast.ImportFrom) and node.module else [])
            for module in modules:
                candidate = ROOT / 'tools' / (module + '.py')
                if candidate.is_file():
                    pending.append(candidate.name)
    return {str(path.relative_to(ROOT)): digest(path) for path in sorted(paths)}


def refresh(rom, regions):
    base = [row for row in regions if row['status'] != 'matching_source']
    report = dict(verified_by_full_progress_build=True,
                  rom_sha256=hashlib.sha256(rom).hexdigest(),
                  non_source_regions_sha256=inventory_digest(base),
                  dependencies_sha256=inputs(), region_count=len(base),
                  scope='Full ROM inventory and original decode/audio/colour comparisons completed before caching. Only unchanged non-source regions are reusable. Each reuse revalidates the current matching source build separately; no new native executions are claimed.')
    CACHE.write_text(json.dumps(report, indent=2) + '\n')


def load(rom):
    cache = json.loads(CACHE.read_text())
    assert cache['verified_by_full_progress_build']
    rom_hash = hashlib.sha256(rom).hexdigest()
    assert cache['rom_sha256'] == rom_hash, 'ROM changed: refresh the full audited inventory'
    assert cache['dependencies_sha256'] == inputs(), 'Inventory inputs changed: refresh the full audited inventory'
    saved = json.loads((ROOT / 'data/rom_regions.json').read_text())
    assert saved['rom_sha256'] == rom_hash
    base = [row for row in saved['regions'] if row['status'] != 'matching_source']
    assert len(base) == cache['region_count']
    assert inventory_digest(base) == cache['non_source_regions_sha256'], 'Audited regions changed: refresh the full inventory'
    return base
