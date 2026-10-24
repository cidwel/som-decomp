# Actor attack-palette preparation and restoration

The complete 75-byte entry at `C1CA04` prepares or restores the palette used
for an actor attack. Carry selects the operation. With carry set, large
actors return immediately; hero actors inspect bit 3 of field `$100` and
restore their fifteen cached palette colors when that bit is set.

With carry clear, the entry selects palette base `$57/$5A/$5D` from the actor
index, initializes fields `$101/$102/$103`, marks field `$100` as `$89`, and
loads the fifteen ROM palette colors through the existing native helper.
The record fields preserve the literal `$CD` temporary and its bit arithmetic.
The entry returns with an eight-bit accumulator after either palette helper.

The readable model reuses the already recovered `ActorCommands.cached_palette`
and `rom_palette` implementations at `C1D8F3` and `C1D90D`; they receive no
new source credit. Twenty-four complete original calls pass for all six
aligned actor records, both carry values and both palette-bit states.
All 37 instruction starts are observed. Entry context is M8/X16, D0, DB7E,
binary arithmetic. Full WRAM outside the observed native stack, returned
registers, flags, context and peripherals match without hooks.

Evidence is in `data/actor_attack_palette_proof.json`, its coverage report and
`data/actor_attack_palette_audit.json`. All 75 source bytes are integrated
and independently assemble to the original ROM; joint acceptance is recorded
in `data/source_checkpoint_20261010_controller_shop_attack_palette.json`.
Movement/attack entry composition and the enclosing actor-action dispatcher
remain separate work.
