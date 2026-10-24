# Directional object-loading windows

`tools/map_object_direction_window.py:DirectionWindow` reconstructs C0E058 (147 new instruction bytes) and upgrades the complete C0E0EB generic window (183 previously recovered bytes) to a full CPU contract. Both independently assemble as a 330-byte component.

The directional entry forces 16-bit registers, reads the selected actor from DP BA and extracts signed horizontal and vertical velocity bytes from E006. Stationary actors use facing F4. Eight movement directions choose literal delta/extent vectors, then share the generic tail. Scroll coordinates A8/AA/AC/AE are converted to tile units and combined with signed byte deltas and extents. Original BIT flags, negative corrections, ADC/SBC carries and unsigned comparison/wrap behavior are retained. The generic entry can select the whole window when object count is below its signed-context threshold; otherwise it uses its fixed vectors and the shared tail.

The report and coverage record 8,192 complete original calls without hooks, 4,096 per entry. Both incoming M/X widths, twelve aligned selected actors, zero/positive/negative velocity boundaries, every facing/count byte and scroll/extent boundaries are covered. Full randomized 128KiB WRAM agrees outside only the three caller return-stack bytes, together with final CPU A/X/Y/flags/S/D/DB and static peripherals. Domain: D=0, DB=7E, binary arithmetic; incoming 8-bit index values are correctly truncated. Eight distinct directional windows were observed.

This closes the window calculation. Cache refill, the complete object scan/creation coordinator and live frame scheduling remain open. No ROM payload is saved.

## Joint source integration: 2026-10-09

Independent ca65/ld65 reconstruction now matches 1,341 blocks and 260 components: 82,054 total source bytes, including 79,496 instructions and 2,558 numeric data bytes; RAM 14,148 and ROM 67,906. This batch adds 1,355 instructions and 8 numeric dispatch bytes, without recounting reused helpers: directional load window 147, boss child definitions 156, actor charge-effect creation 694, descriptor-four callbacks and targeting helpers 358. Their complete original-execution reports remain separate from the matching assembly proof. Palette transition lifetime additionally passes 10,372 original calls but adds no instruction bytes. Documented ROM union is 813,670 / 2,097,152 = 38.79880905151367%, distinct from code decompilation; complete code denominator and full ROM rebuild remain open.
