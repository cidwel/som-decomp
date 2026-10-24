# Native menu navigation, row attributes and icon expansion

Eight reconstructed bodies totaling 506 candidate instruction bytes passed 35 directed original calls after an eight-entry smoke. The corrected direction-down replay also passed. A separate one-call supplement closes the sole missing BRA C0672F without modifying or repeating the successful primary. Combined evidence observes **254/254 instruction starts**, with all eight bodies recoverable at unambiguous immediate widths and boundaries.

The first complete capture exposed a literal M8 TXA mismatch: the original copied the low byte of X=FFFF, while the model passed the full word to its byte helper. Only the mutable vertical producer was corrected to mask X&255; all frozen text/vblank dependencies remained unchanged. The exact replay and corrected complete comparison passed.

The produced ABI is D=0, DB=00, binary, M16/X16 entry context. Cases cover category/row persistence, both packed weapon/armor rank fields, sparse nonzero equipment lookups, repeat-start/continue/busy/stop/idle paths, up/down guards, conditional tile segments and active/inactive/no-hero OAM row attachments. Three original icon IDs (0,123,255) and explicit zero/alternating/ones plane patterns exercise complete runtime graphic expansion from three planes to four planes, including native palette-base conversion and original source/output cursors. ROM graphics and tables are read at runtime only; no assets are persisted.

Full WRAM outside the observed stack, CPU result, S/D/DB and peripheral/input/audio state match without hooks. D0CA6E is a genuine prefix that calls D0CA8B three times and falls through to its fourth expansion; the composed entry model preserves this native return structure. The final VRAM icon upload and interactive outer menu loop remain open.

| Entry | Bytes | Reconstructed body | Starts |
|---|---:|---|---:|
| C06B4C | 150 | `persist_native_menu_category_row_and_equipment_rank` | 66/66 |
| C066F3 | 77 | `update_native_menu_horizontal_repeat_and_description_request` | 33/33 |
| C06740 | 53 | `request_native_menu_vertical_inventory_transition` | 23/23 |
| C0709C | 7 | `add_native_menu_row_tile_segment_when_comparison_carries` | 4/4 |
| C070A3 | 56 | `bind_native_menu_list_row_to_active_hero_oam_marker` | 32/32 |
| D0CA6E | 29 | `prepare_four_native_menu_icon_tiles_from_original_graphics` | 17/17 |
| D0CA8B | 75 | `expand_one_native_menu_icon_tile_into_output_rows` | 41/41 |
| D0CAD6 | 59 | `convert_native_menu_icon_pixels_with_selected_palette_base` | 38/38 |

Integration spec: `event_menu_navigation_icons_check:EventMenuIconPixels:event-menu-navigation-icons:event_menu_icon_pixels`; supplemental validation is `event_menu_navigation_icons_guard.py`. All three new model modules, checker, guard, reports and captures are frozen. Exact source credit follows parent physical-overlap review and independent assembly, without double-counting already proven text/vblank dependencies.

Frozen artifact SHA-256:

- `tools/event_menu_navigation_state.py`: `bfe1ac9e7de4a42a1d2a425a99d83841a089c68be7c4aef79401f4bff8e5b5ec`
- `tools/event_menu_list_attributes.py`: `a8bc82a92b9027513799ad072cb62c84d0028f69e747e54a6a56d4f5db7d0d26`
- `tools/event_menu_icon_pixels.py`: `c2d4a5b3f1e9603cd8a83af562f73e36da106ce28e9979fc0ff3a5ebc5ca6b17`
- `tools/event_menu_navigation_icons_check.py`: `2d5e74a9a1dde3edba9526078cb487e9ce4e9bd8d4141817a8e89bca7ed57f51`
- `tools/event_menu_navigation_icons_guard.py`: `136fc7c7d8d37a09fff20e49c11176e9e188a3187dabe10a7fb0da03d63a05d6`
- `data/event_menu_navigation_icons.json`: `fbbd26bd8d1621bb579e6e643ad213554d840caa0772348d6ff04ca5dc9fd62d`
- `data/event_menu_navigation_icons.coverage.json`: `8912dab1e78c03a62c49ee31608c79a36bd6ef0a16ccf8af366e5bdfadd852b6`
- `data/event_menu_navigation_icons_guard.json`: `6b716900ae43fc642c2ea25c90a0bd15da7665d5b84594fd5e9d7da7618809da`
- `data/event_menu_navigation_icons_guard.coverage.json`: `d3891b59cb9e2b6ca1419e5f3c316316620982afa5e29138fbce58e38b8dbf9c`
- `data/event_menu_navigation_icons.source_audit.json`: `5f81f1b4a5512d08e30f04b43d7fc9e686ab0d47c12cbbbd5669ab96bb215194`
