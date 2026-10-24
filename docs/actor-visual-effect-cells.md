# Native three-cell actor effects

C18D80 updates the actor's three sixteen-byte effect cells. Empty cells finish the effect and either transfer pending cast presentation, restore weapon graphics, or apply the enemy/deferred-state guards. Kind4 holds the update. Other kinds visit offsets0,16,32; the last visit falls through rather than allocating another call frame.

C18DDE decrements a cell's delay, raises its speed by two until the recorded limit, and retires cells targeting absent or negative-state actors. A live target is passed to the complete C18E93 steering routine with the cell's heading/speed, fractional bytes and world-relative position. A distant target updates all those fields; the close guard falls into C18E74. That routine applies the actual C18D12→D04C82→C8E6D4 spell/reflection chain and either retires the cell or stores the reflected target returned with carry set. Existing presentation and weapon restoration execute their complete models; no hit, audio, status, RNG or palette helper is replaced.

Primary smoke3 and first full31 passed. Primary fixtures inherited an already-hit target list, so their nominal damage/status/lunar cases exercise the real duplicate-hit guard. The names `status` and `lunar` in those immutable fixtures also referred to spell IDs12 and37; both dispatch to the ROM's ordinary damage handler, not status-only or LunarMagic. A separate fresh-first-hit supplement7 sets the target list to FF before execution and compares positive damage, target registration, five ordered ACK audio writes, and actual Wall redirection. A final two-call supplement uses the correct ROM IDs26 (C8EEF5 LunarMagic) and20 (C8EBF4 status-only); both complete their real handlers. All three captures remain independent and immutable, with no repetition of the primary31.

The combined audit observes all130/130 instruction starts and immediate widths across275 bytes; the reconstructed bodies assemble exactly. Genuine captures contain2720 PC/width states. Every recorded dependency hash remains unchanged. Comparison includes all WRAM outside the measured native stack, nine CPU result fields, S/D/DB/arithmetic mode, graphics/audio/arithmetic peripherals, ordered audio writes and explicit raster/IRQ/ACK state. The native domain is D0/DB7E/M8/X16/binary, aligned ordinary actor slots, three fixed cells, valid cast resources and finite scripted external IRQ/ACK inputs. No instruction hooks are installed. This closes the effect-cell worker contract, not a full gameplay frame or arbitrary malformed actor memory.

C18DAB/26 already has `restore_actor_weapon_after_cast.s`. New source credit is therefore249 instructions: C18D80/43 before that existing body, C18DC5/25 after it, C18DDE/150 and C18E74/31. The complete logical C18D80 proof spans94 bytes, preserving the existing26-byte interior source. The C18DC5 range is an internal branch/fallthrough component of C18D80, not a separately asserted public ABI.

Integration spec: `actor_visual_effect_cells_check:ActorVisualEffectCells:actor-visual-effect-cells:actor_visual_effect_cells`. Additional genuine evidence: `actor_visual_effect_cells_positive` (7 calls) and `actor_visual_effect_cells_spell_handlers` (2 calls). `data/actor_visual_effect_cells.source_audit.json` records provenance and the four new physical partitions.

Reusable interface: `ActorVisualEffectCells(rom,cpu).effect_cells()` or `.run(0xC18D80)`, `.advance_cell()` for C18DDE and `.cell_hit()` for C18E74. `.result()` returns A/X/Y/C/N/Z/V/M/XF; the CPU and its real stack/context/peripherals are shared. The producer used by the supplements is `actor_visual_effect_cells_positive.prepare`, followed by the explicit correct spell IDs from `actor_visual_effect_cells_spell_handlers.prepare`. The CPU/environment is the frozen `actor_cast_entity_engine.native_engine_environment`/ModeTwoCPU, with real raster IRQ entry and ACK handling; proof fixtures reuse the verified cast resource setup. Boss callers must preserve their actual outer JSL/JSR/PHX frames.

Next connected frontier is the original point/trail producer C2A480..C2A6C5, which initializes the arrays and cadence consumed by the already-verified Motion model. Its frame parser and native nonlocal FF termination are still open.

## Frozen hashes

- `tools/actor_visual_effect_cells.py`: `2d6bb3a40e4896bab58e823f000eb3e4ae703375f1c51545b4cd0922676f2334`
- `tools/actor_visual_effect_cells_check.py`: `7053b62c1aecce4e6664a99ba4bddec877f28a425b024522d1a9b644237084f9`
- `tools/actor_visual_effect_cells_positive.py`: `ed700fde15cd59e016fe920c1b65de67bbb7df8b308118d425d65aac68a19374`
- `tools/actor_visual_effect_cells_spell_handlers.py`: `a2b080282682bf37f925ad9a7143a9102664bdfc4c1dd883bf8e186fe347aa30`
- `data/actor_visual_effect_cells.json`: `c16abee5c5e5a4dd5c31421a068300c302cfda28766c132a61f3d9241f3b872c`
- `data/actor_visual_effect_cells.coverage.json`: `bdbd2cba6701c0c1bb3250e2a1cda2dd1a597bd4b84ed6084305baa9345b4cdc`
- `data/actor_visual_effect_cells_positive.json`: `5ee650c276c2389b9a0da146b843cf4136270c7d5727fd27f44519bd52c30b0f`
- `data/actor_visual_effect_cells_positive.coverage.json`: `d29363a1cf3630a7ac8501e7d0215a60b09896ee1cd45e3d182252b4f9aef534`
- `data/actor_visual_effect_cells_spell_handlers.json`: `4c8695662c0da46c0261febed0ac0852d2deb708808942241c4bffb3227d874b`
- `data/actor_visual_effect_cells_spell_handlers.coverage.json`: `85110d85c23cd7463fe7144504de3a324e25c225ea7d474ad54efa3ddbb580d7`
- `data/actor_visual_effect_cells.source_audit.json`: `0da797443bd66bad7693d14455d3404dda8fa1cf7f29d12df95f6baf61af727e`
