# Readable C routines (T3)

Each file holds one original routine as C that compiles and passes the differential test against the original code.
File name: `<ADDR>_<routine_name>.c`; the header comment gives class, size, entry state and the registers callers read.
`SOM_REGISTER(..., "gen" | "hand", ...)` at the end of a file registers it with the test harness (`tools/decomp_c/rt`).
"gen" files are produced by `tools/decomp_c/gen/` and are overwritten by `make generate`; files registered as "hand" are written by hand and never overwritten.

## Re-verify everything

```
make -C tools/decomp_c verify      # rebuild all, run traces + fuzz + synthetic + mutation, rewrite data/decomp_c_status.json
make -C tools/decomp_c generate    # regenerate the "gen" files (class A) from src/rom/*.s
python3 tools/decomp_c/batch.py verify --class B   # generate and verify class B
python3 tools/decomp_c/batch.py recheck --only C0505B,C0532C   # re-verify a few routines
```

Needs the ROM (existing tool path), the capture directories under `~/.local/state/som-decomp/` and the LakeSnes copy; see `docs/decomp-c-sizing-20261017.md`.
Rules learned from failures: `docs/decomp-c-rules-20261018.md`. Counts and estimate: `docs/decomp-c-progress-20261018.md`.

## Map by subsystem (verified routines / bytes verified / other statuses)

| directory | what | verified | verified bytes | failing | hardware model | untraced |
|---|---|---|---|---|---|---|
| `audio/` | sound requests and audio macro senders | 8 | 168 | 0 | 0 | 4 |
| `battle/` | damage, hit test, critical, charge gauge, status timers, flinch, spell hit bookkeeping | 141 | 9297 | 12 | 5 | 21 |
| `boot/` | boot, reset and title helpers, code decompressed to WRAM | 150 | 7646 | 11 | 7 | 95 |
| `graphics/` | sprite, palette, tile and HDMA helpers | 115 | 6590 | 9 | 0 | 77 |
| `item/` | item and inventory ring routines | 52 | 2718 | 13 | 2 | 12 |
| `map/` | map loading, scrolling and event helpers | 170 | 12367 | 18 | 6 | 43 |
| `menu/` | menus, dialogue windows, party status screens | 247 | 10569 | 23 | 2 | 70 |
| `misc/` | routines that match no subsystem keyword | 404 | 20102 | 20 | 1 | 137 |
| `monster_ai/` | monster actor scripts and AI helpers | 292 | 10616 | 21 | 11 | 183 |
| `spell/` | spell cast, spell target and status-spell routines | 108 | 5494 | 18 | 3 | 179 |

`common/` holds `som_c.h` (macros), `wram_names.h` (generated from `gen/somnames.py`).

## Hand-written battle routines (readable, named, same verification)

| address | routine | role (docs/rom-combat.md) |
|---|---|---|
| C04FED | `calculate_physical_defence_terms` | evasion and defence of the defender with buff/debuff and Pygmy adjustments, section 4.3 |
| C0505B | `test_physical_hit_accuracy` | hit test: accuracy against evade/2 + random share, section 4.2 |
| C0532C | `apply_critical_hit_or_weapon_gauge` | critical hit, Saber counter and weapon-gauge damage scaling, section 4.3 |
| C8E6D4 | `apply_spell_hit_to_actor` | spell hit bookkeeping (hit list, MP cost, flash timers) and the `resolve_spell_hit_on_target` dispatcher over spell ids 0-41 (class C, `battle/`) |

Other battle routines in `battle/` (generated, verified): C04F7B resolve_actor_pending_physical_hits, C05119 queue_physical_weapon_status_after_damage, C03D1C/C03D31/C03D4D status timer groups, C03D5F status damage timer, C03E80 rebuild_actor_stats_and_record_status_change_flags, C03C19 coordinate_actor_combat_status_and_buff_timers.
The earlier disagreement on the order of math-unit writes (C0514B, C052E7, C8E990, C8EA8B) was a logging gap of the first capture core, not a hardware difference; see `docs/decomp-c-rules-20261018.md` rule 21.

## Mechanical tier

`batch.py mech` lifts the routines without readable verified C instruction by instruction (`lift.py`, variant "lift") and tests them strictly. The result is stored under `mechanical` in `data/decomp_c_status.json`; the generated code is not committed and is not counted as readable C.
