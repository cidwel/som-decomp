# Created palette effects through pool completion

`tools/boss_palette_transition_update.py:TransitionPool` closes a previously unverified composition: original paired palette-effect creation through the actual nine-slot boss pool, its indirect definition dispatch, the complete palette phase machine and carry-driven termination. It adds **zero instruction-byte credit**: `boss_palette_animation.py` already recovers the transition body and native arithmetic. This prevents double counting while proving that the recovered pieces execute together.

## Existing entry points and source extents

| Entry | Source bytes | Role |
| --- | ---: | --- |
| C2272D | 31 | Allocate definition274C, flags6000, preserving failed-call operands |
| C2274C | 117 | Immediate exact target copy or full/single-color transition dispatch |
| C20F83 | 14 | Increment actor96/AD and dispatch actor8E through a real indirect call |
| C20DB2 | 144 | Traverse nine slots, apply native phase/flag guards, execute definitions, remove completed objects |

The existing transition continuations are reused unchanged: C227C1 (13), C227DC (8), C227F2 (105), C2285B (107), C228C6 (52), C228FA (25), C22913/C22934/C22955 (33 each), C22976 (28), C22992 (7), C22999 (36), C229BD/C229EA (45 each), C22A17 (16), C22A27 (48), C22A57 (2). Their native unsigned/signed software division is C22CBF (39) and C22D69 (60). Numeric seven-entry phase tables remain existing reconstructed data, not instructions. Detailed channel arithmetic is in `docs/graphics.md`, “Complete palette-transition phase machine and software division.”

## Lifecycle behavior

Two ordered original creator calls attempt allocation among slots3–8. A successful object carries its duration, target palette identity and full/single-color slot word into the next real pool invocation. Actor flags6000 bypass ordinary combat and phase/freeze guards; existing occupied actors use their native phase guard and remain intact. This is an explicit supplied scheduling boundary, not an invented allocation-only model.

Duration zero copies the exact target immediately. Nonzero duration runs initialization, four derive/spacer phases, fixed-point stepping and the final target correction. Every call is dispatched through C20F83; the actual software divider executes in the original CPU. Returned carry makes C20DB2 clear the object’s word0, word8C and active-slot byte. A further complete pool pass proves that removed object storage and completed palette output stay unchanged. Completion leaves the native object workspace intact; the model does not zero the whole record.

Independent final assertions compare selected software palette words with the original ROM’s target lookup. Full-palette transitions must end at all16 exact target words. Single-color mode must change only its selected color; every unselected software palette byte remains unchanged. Existing occupied512-byte actor records are checked in full after every step. Allocation patterns cover zero, one and two available requested effects, including first-success/second-failure exhaustion.

## Verified evidence

The report records **10,372 complete original calls**, **640 persistent paired-effect sequences**, **9,092 full pool updates**, **1,200 successful creations** and **80 failures**. All64 eligible occupancy masks × durations0/1/2/7/32 × full/single modes are covered. Every phase0..6 in both modes is observed. The trace contains **542 PC/M/X states** and the report hashes **87 dependencies**.

After each call, full randomized128KiB WRAM outside129 native call-frame bytes, all static peripheral state, A/X/Y/C/N/Z/V/M/XF and S/D/DB agree. The replacement nmi_ppu.CPU has no instruction-bypass hooks. No original palette, script or graphics payload is stored.

Reproduce from ``:

```bash
python3 tools/coverage_run.py 'baserom.sfc' data/boss_palette_transition_update.coverage.json tools/boss_palette_transition_update.py --json data/boss_palette_transition_update.json
```

ROM SHA-256: `4c15013131351e694e05f22e38bb1b3e4031dedac77ec75abecebe8520d82d5f`.

## Domain and remaining limits

Binary arithmetic, M16/X16, D0200/DB7E, required zero sentinel02C5, nine aligned boss slots and supplied pool phase1. Targets sample256 palette identities; selected slots are6/7 and all16 single-color indices occur. Frozen-context flags are sampled and created6000 effects retain the literal bypass. Existing occupied objects are phase-skipped, so this proof does not execute their unrelated definitions.

Arbitrary pool-phase scheduling, nonzero sentinels, out-of-table phases, overlapping target palettes, hardware CGRAM publication, live interrupts/rendering/timing and every other boss definition remain open. Existing standalone proofs retain their wider palette-slot/arithmetic domains; this composed proof claims only its own fixture domain.

## Joint source integration: 2026-10-09

Independent ca65/ld65 reconstruction now matches 1,341 blocks and 260 components: 82,054 total source bytes, including 79,496 instructions and 2,558 numeric data bytes; RAM 14,148 and ROM 67,906. This batch adds 1,355 instructions and 8 numeric dispatch bytes, without recounting reused helpers: directional load window 147, boss child definitions 156, actor charge-effect creation 694, descriptor-four callbacks and targeting helpers 358. Their complete original-execution reports remain separate from the matching assembly proof. Palette transition lifetime additionally passes 10,372 original calls but adds no instruction bytes. Documented ROM union is 813,670 / 2,097,152 = 38.79880905151367%, distinct from code decompilation; complete code denominator and full ROM rebuild remain open.
