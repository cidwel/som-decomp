# Native menu icon objects and upload

Six reconstructed routines cover 232 bytes: D0C83F/23 hides icon OAM objects; D0C86C/55 resolves twelve descriptor words; D0C976/3 sets the VRAM cursor and falls through; D0C979/13 advances the palette and selects a tile; D0C986/118 expands and transfers two tile rows; D0C9FC/20 advances the palette base modulo fifteen. The original descriptor and graphics tables are read at runtime. No ROM payload is saved.

## Original execution evidence

The smoke of three calls and the first full capture of seven directed calls passed without model corrections. Cases include mixed missing/present descriptors, palette wrap, an absent icon under the native forced-upload guard, selected icons 123/255, a vblank already in progress, and two actual vblank edges. Both edge cases execute the original C0C0A8 interrupt handler and RTI once. The phase clock is an explicit external event, bounded to the actual polling instruction D0C993. It does not replace the handler or claim a complete hardware timing model. Frozen Vblank and pixel-expansion dependencies are reused unchanged.

The proof compares all WRAM outside the observed native stack, VRAM/CGRAM and PPU/DMA peripherals, registers and flags, return context, input/audio state and frame events. Native near versus long return contracts, saved X, byte-index truncation and the two 64-byte DMA transfers are preserved.

The source audit observes **108/108 instruction starts**, all six exact routine boundaries and every immediate width, in 261 captured PC/M/X states. All 198 dependency hashes still match. Report, capture, audit, models and checker are now frozen. Independent assembly and physical-overlap accounting remain the integrator's responsibility.

Integration spec: `event_menu_icon_upload_check:EventMenuIconUpload:event-menu-icon-upload:event_menu_icon_upload`.

## Remaining menu chain

Palette assembly D0CB1F/CB2F and twelve-grid/equipment-preview publication D0C8FB/C90B are being reconstructed in separate files. D0CB11 requires descriptor preparation D0D308; the outer C066B5/C0666F menu, list constructor and action consumers remain open. This delivery does not claim that the full menu engine is complete.

## Frozen file hashes

- `tools/event_menu_icon_objects.py`: `508a48203eb8992997d781c20d04eeecfcde243babca532a7002824fff00d819`
- `tools/event_menu_icon_upload.py`: `8fc648e5447fd0d98fc9b7ae995f6f7e614f29b632ce2e3764a39ca8a074d3c7`
- `tools/event_menu_icon_upload_check.py`: `7ff16a3d30c7f7c06b51d90f4a17bcc34fc8c01351c07b39a27d687407f0b5df`
- `data/event_menu_icon_upload.json`: `e21055a42d57f4ac8696f364de1dfc9de2d7a59360e7f275c7b25af97fbe46cb`
- `data/event_menu_icon_upload.coverage.json`: `f20ade144a7eeee7076b73a495fbe5f89d587a1e258bd90cfbe9256922fa607a`
- `data/event_menu_icon_upload.source_audit.json`: `1b7c4cb550292623c56c6d98df270022265d29d073b3126c4f168f5404024c1f`
