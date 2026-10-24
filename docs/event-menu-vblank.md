# Native menu vblank, palette and window script drivers

Five native vblank/poll contracts, three palette dimming/restoration bodies, two palette wrappers and five open/close/numeric script fragments passed 28 directed original calls after a five-entry smoke. The first complete capture passed without corrections. The source audit observes **104/104 instruction starts across 15 bodies**, totaling 254 candidate bytes; every immediate width and boundary is recoverable. The capture contains 2,103 PC/M/X states.

Vblank fall/rise phases are explicit external bus events. Each rising edge delivers the actual C0C0A8 native frame handler and RTI in the CPU, compared with the complete reconstructed map-frame model. This is a bounded map-NMI context, without a claim that the unrelated full-menu handler C020A7 is installed here. No hook replaces a handler, no window-active flag is forced clear and no return is fabricated. PPU access during the explicit vblank phase is permitted without changing the forced-blank register value.

The produced ABI is native D=0, DB=00, binary, M16/X16. Every entry is exercised; extra cases cover positive text preparation, prior active windows, alternate menu mode, both window-skip routes and both palette branches. Original open, close and numeric scripts consume eight, fifteen and eight frames respectively in the baseline fixtures; prior active-window handling consumes nine. The original ROM scripts and palette/graphics assets are read only at runtime.

Full WRAM outside the observed hardware/callee stack, CPU result, S/D/DB, PPU/DMA/arithmetic peripherals, input/audio state, vblank reads and NMI deliveries match. Entry C0693F/C0695A is a long wrapper over a near call. C0695E, D0CD27, D0D572/D599/D5A0 and D0D5B2 are real fallthrough/prefix/shared-tail contracts; captured caller context preserves the complete native return chain, rather than inventing an RTS at a fragment boundary.

| Entry | Bytes | Reconstructed body | Starts |
|---|---:|---|---:|
| C0693F | 4 | `wait_menu_vblank_through_native_long_wrapper` | 2/2 |
| C06943 | 23 | `await_vblank_edge_and_run_complete_menu_text_frame` | 10/10 |
| C0695A | 4 | `wait_vblank_and_poll_menu_through_native_long_wrapper` | 2/2 |
| C0695E | 3 | `wait_vblank_before_polling_native_menu_input` | 1/1 |
| C06961 | 22 | `poll_native_menu_controller_and_publish_input_word` | 9/9 |
| D0CD35 | 39 | `dim_menu_palette_preserving_first_actor_row_when_requested` | 16/16 |
| D0CD5C | 17 | `save_and_halve_one_menu_palette_color` | 8/8 |
| D0CD6D | 33 | `restore_saved_menu_palette_and_request_upload` | 13/13 |
| D0CD27 | 3 | `initialize_palette_then_fall_through_to_native_menu_dimming` | 1/1 |
| D0CD2A | 11 | `dim_palette_request_upload_and_await_real_menu_vblank` | 4/4 |
| D0D572 | 4 | `await_menu_vblank_then_fall_through_to_text_transition` | 1/1 |
| D0D576 | 35 | `await_prior_dialogue_or_start_native_menu_window_open` | 15/15 |
| D0D599 | 7 | `select_native_numeric_menu_window_script` | 3/3 |
| D0D5A0 | 18 | `select_native_menu_window_close_script_when_needed` | 7/7 |
| D0D5B2 | 31 | `run_selected_menu_window_script_through_real_vblank_completion` | 12/12 |

Integration spec: `event_menu_vblank_check:EventMenuTextDriver:event-menu-vblank:event_menu_text_driver`. All four new model modules, checker, report and capture are frozen. The interactive setup C066B5, list construction and the outer C0666F loop remain open; this result closes their real vblank and window-script dependencies, not those coordinators. Candidate byte credit remains conditional on parent overlap review and exact assembly.

Frozen artifact SHA-256:

- `tools/event_menu_vblank.py`: `7afa910054bc21238051f33ca63f6f0a16cff9331b24e4f76d526a39144dbf8f`
- `tools/event_menu_palette_dimming.py`: `d80a706f9634f7360d5436c73c206fe1a5446eb6d886dae7e6311767280d47f6`
- `tools/event_menu_palette_driver.py`: `84cfbdad4407cd2cede98253975b1ca91891d851c4ce1747c58badcc79602aa4`
- `tools/event_menu_text_driver.py`: `f99a46c0071dcf35f391891ecee5bc864393f42e13e3281f9fcb5fb805e745ab`
- `tools/event_menu_vblank_check.py`: `1ab8ea22470d846bd194da933c63f2d638ea81e51a1941124b67c73de467e1a9`
- `data/event_menu_vblank.json`: `dbfcc7cdf478a0b03b2deb1362fbe75967fa26ac31b7503e5f8d332f0cb5ad8e`
- `data/event_menu_vblank.coverage.json`: `63038b3e95e0971558c60aa0651f1ef0b0cdb3470affcfba662ac2592fd78dad`
- `data/event_menu_vblank.source_audit.json`: `340e3ba4a4161aaa212f5974fb55d8e58d0273b352343c5319370b3404c736d6`
