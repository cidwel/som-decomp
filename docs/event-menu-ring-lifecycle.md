# Native ring interface lifecycle and public exit

C066B5/62 reconstructs palette/vblank preparation, text startup, glyph DMA, request/poll, held-cancel flag, phase initialization and actual descriptor-list expansion. C06608/8 composes text shutdown and shadow palette restore, then C06610/7 clears overlapping DP cursor words exactly. C065BE/25 performs the real three-hero controls when required, closes dialogue outside modal context and tails into the existing C0645C saved-context epilogue.

Smoke2 and the first full7 passed: normal initialization, physical cancel retained during startup, text/palette close, cursor clear, party-controls exit, ordinary dialogue exit and modal exit. Public exit is entered with the native JSL frame plus saved P/DB/D bytes; the model restores that literal stack context and the original performs RTL. It does not invent a near return. Other entries use their real near-call frame. Rendering/palette/DMA, input timeline, audio, real NMI/RTI, WRAM and full CPU/context match without hooks. Discarded ordinary call frames are excluded by the observed watermark while observable caller context and peripheral transfers remain compared.

All37/37 own instruction starts and immediate widths are observed,2,076 distinct PCs and286 dependency hashes unchanged. Four bodies total102 candidate new instruction bytes, with no physical manifest overlap at preparation. Existing saved-context C0645C and all complete text, palette, rendering, polling and party-service dependencies receive zero duplicate credit. The main interactive loop, category-two page branches and shop actions remain open; this lifecycle proof does not close event opcode2E.

Integration spec: `event_menu_ring_lifecycle_check:EventMenuRingLifecycle:event-menu-ring-lifecycle:event_menu_ring_lifecycle`.

## Frozen hashes

- `tools/event_menu_ring_lifecycle.py`: `9439d86f36d5454fc4e6c0574bcbca17e7fdc236df0e8f2600f1db6141093a53`
- `tools/event_menu_ring_lifecycle_check.py`: `9aa289c301a84bf5830d93faada99f8e90fafa473c8ce3f47502491d777c9bc8`
- `data/event_menu_ring_lifecycle.json`: `1473e90f843a7571033d9c94f801f3e25deb5d822698d89079a571fbfa6dcaa4`
- `data/event_menu_ring_lifecycle.coverage.json`: `9d943860996c383254f876e612bcd51660c88d946df3566bdaf3d1836c3c3522`
- `data/event_menu_ring_lifecycle.source_audit.json`: `1169cbd7a097c24b058f4b9d7b02669c268a617d527849430523d105d25726bc`

Source acceptance: all 102 new instruction bytes are integrated and independently assemble to the original ROM. The joint checkpoint is `data/source_checkpoint_20261010_actor_targets_equipment_ring_name.json`.
