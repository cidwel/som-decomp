# Complete cast execution comparison

292 original calls pass for the root CastExecution model: C18707/C18775/C18DAB64 each, C18C9616 and C18D0984. The final capture records10,903 PC/M/X states. C18707 uses its original JSL/RTL public contract; the other four are JSR/RTS internal entries. No instruction hooks are installed.

The fixtures execute hero graphics and ordinary three-target success/cancel branches, real twelve-actor/HUD sprite preparation, all seven native entity scheduler families during cancellation, original random fallback and linked twin reentry, actual hit/reflection handlers for all42 spell IDs and weapon restoration. Both ordinary presentation branches C18784 and C18787 are present in the trace, as are real fallback callbacks. Spell/render/target success is not replaced by empty guards. Full cast-engine fixtures use one live target and optional additional native hit slots; root's separate EngineTargets21 comparison adds all seven families with1..3 scheduler targets.

Every call compares randomized WRAM outside the observed transient native stack footprint, CPU flags/result and S/D/DB, PPU/DMA/arithmetic peripherals, ordered audio writes and acknowledgement state, and explicit external IRQ inputs. Native stack watermarks remain within1E62..1EFD and active cast cancellation uses up to504 actual IRQ entries. External inputs specify raster225/VBlank1, a2048-edge IRQ budget and four acknowledgement delays; no console timing claim is made. Ninety direct/model dependencies match the report; a conservative154-module static import closure separately captures dynamically composed renderer/helper dependencies.

Width/boundary recovery passes C18707110, C1877577, C18C96115 and C18D099:311 candidate instruction bytes. C18DAB26 reuses the already complete CastWeaponRestore512 evidence/source, including its boss5C-negative deferred state branch. This comparison deliberately keeps ordinary/HUD rendering active and does not repeat that isolated boss guard. Integration determines actual new source credit without counting any earlier helpers/family bodies twice.

An initial checker error used a JSR frame for public C18707; ROM RTL sites identified and corrected only the caller ABI. The first full comparison then exposed an actual composition gap at C18D09 trial38: elemental level-up sound recorded a packet but left the model acknowledgement echo unchanged. Root added the native sound packet replay/ACK adapter, preserving earlier dependency models. Exact-case reproduction then passed and the292-call capture passed. No WRAM/peripheral differences were hidden.

The reproducible fixture function is fixture(cpu,entry,trial,rng); native engine CPU/IRQ setup remains in actor_cast_entity_engine. The diagnostic CLI --entry C18D09 --trial38 consumes the same preceding fixture randomization without emulating other calls. Neither ROM bytes nor assets are stored.

tools/actor_cast_execution.py: `da8dbe449de061fc6ab3db3695a2317e3600917d45a26a75714a2ff268402598`.

tools/actor_cast_execution_check.py: `d4efe3375798389ea0a0ad1e1ff5aef5dafe77d4f08cc1d9b6379c5e6bcb8fe7`.

data/actor_cast_execution_check.json: `19bd315f5c56aeeb65a895faf913291b9a0ff5acebde10503ce56d383dc7913b`.

data/actor_cast_execution_check.coverage.json: `3f3b779683f212c8d4efeea5ff8e0b5140d211a6146e0c4235ac68358bb3e525`.

data/actor_cast_execution_check.dependencies.json: `7b3d75f983426e3a36c54b512986494c5b2975bcbbfbbcc3cd66525fb04d7f45`.
