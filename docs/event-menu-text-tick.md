# Native menu text frame and description producers

The original 204 directed calls passed after the 37-entry smoke. These calls compose 37 newly reconstructed bodies, totaling 2,155 candidate instruction bytes, with actual first/second-line preparation and the complete public dialogue coordinator. They do not execute the interactive outer menu driver.

The first smoke exposed a carry mismatch in byte additions with a nonzero accumulator high byte. Only the mutable menu models were corrected to pass masked byte operands to the existing arithmetic helper; all frozen dependencies remained unchanged. The corrected smoke and first complete capture both passed.

The domain is produced native D=0, DB=00, binary, M16/X16 entry context. Seven description categories, four menu modes, sparse equipment lists, original price tables, item eligibility, hardware division, consumable quantities and temporary armor insertion with three real stat rebuilds are covered. Full WRAM outside the observed stack, CPU result, S/D/DB, PPU/DMA/arithmetic registers, controller state and audio packets are compared. No hooks bypass callees.

Primary audit: **956/1003 instruction starts**, 30/37 complete bodies. The remaining 47 starts belong to seven bodies; primary evidence must not be described as a complete source contract for those seven. A separate 15-call directed supplement is prepared, with no new-byte credit and no primary recapture.

| Entry | Bytes | Name | Primary starts |
|---|---:|---|---|
| D0D5D7 | 28 | `set_native_menu_dialogue_script_and_close_prior_window` | Complete |
| C06BE2 | 22 | `calculate_wrapped_native_menu_row_index` | Supplement pending |
| D0D530 | 52 | `add_wrapped_menu_row_to_inventory_label_offset` | Supplement pending |
| D0D0B0 | 42 | `locate_selected_weapon_with_nonzero_level` | Supplement pending |
| D0D0DA | 33 | `locate_selected_armor_with_nonzero_level` | Complete |
| D0D1FB | 52 | `offset_armor_inventory_description_by_position` | Complete |
| D0CE5D | 130 | `publish_selected_equipment_description_row` | Supplement pending |
| D0D3F0 | 320 | `select_complete_native_menu_description_script` | Supplement pending |
| D0D787 | 34 | `append_menu_stat_value_and_separator` | Complete |
| D0D7A9 | 15 | `append_menu_stat_value_and_terminator` | Complete |
| D0D7B8 | 42 | `append_native_two_or_three_digit_menu_number` | Complete |
| D0D7E2 | 23 | `divide_menu_number_using_snes_arithmetic_registers` | Complete |
| D0D7F9 | 4 | `divide_and_append_native_menu_digit` | Complete |
| D0D7FD | 37 | `append_native_menu_digit_with_leading_zero_suppression` | Complete |
| D0C800 | 63 | `locate_menu_category_inventory_and_equipment_spans` | Complete |
| D0D9B4 | 11 | `read_consumable_inventory_quantity` | Complete |
| D0D9BF | 15 | `read_consumable_inventory_record` | Complete |
| D0D9DE | 24 | `read_item_base_stat_from_native_ten_byte_table` | Complete |
| C07A02 | 38 | `read_native_item_usability_and_category_bits` | Complete |
| C079C7 | 50 | `test_native_menu_item_eligibility_for_selected_hero` | Complete |
| C07C4C | 47 | `resolve_selected_armor_inventory_row_and_description_id` | Complete |
| D0D9CE | 16 | `rebuild_selected_hero_attributes_for_menu_description` | Complete |
| D0D624 | 75 | `format_consumable_inventory_quantity_description` | Supplement pending |
| D0D66F | 81 | `format_selected_equipment_current_and_candidate_stat` | Complete |
| D0D6C0 | 96 | `compare_armor_stat_using_temporary_real_equipment_rebuild` | Complete |
| D0D720 | 103 | `compare_item_base_stat_after_real_hero_eligibility_test` | Complete |
| C0793D | 13 | `hide_shop_hero_markers_before_price_selection` | Complete |
| C07CD4 | 57 | `adjust_menu_price_for_shop_and_inventory_modes` | Complete |
| D0D9F6 | 71 | `publish_shop_item_eligible_hero_markers` | Complete |
| D0DA3D | 35 | `place_one_eligible_active_hero_shop_marker` | Complete |
| D0D8E8 | 204 | `calculate_complete_native_menu_item_price` | Complete |
| D0D8DE | 10 | `calculate_menu_item_price_preserving_register_context` | Complete |
| D0D5F3 | 35 | `dispatch_native_menu_second_line_description` | Supplement pending |
| D0D822 | 124 | `render_complete_menu_price_or_armor_selection_description` | Complete |
| D0D89E | 40 | `format_native_menu_price_with_five_decimal_places` | Complete |
| D0D8C6 | 24 | `emit_one_menu_price_digit_by_repeated_word_subtraction` | Complete |
| D0D397 | 89 | `prepare_and_run_complete_native_menu_dialogue_frame` | Complete |

Unobserved primary starts:

- C06BE2: C06BF0, C06BF1
- D0D530: D0D54E, D0D54F, D0D552, D0D553, D0D556, D0D558, D0D55B
- D0D0B0: D0D0BF
- D0CE5D: D0CE7F, D0CE80
- D0D3F0: D0D405, D0D408, D0D40B, D0D411, D0D414, D0D417, D0D418, D0D419, D0D41C, D0D43B, D0D43F, D0D466, D0D467, D0D4AD, D0D4AF, D0D4B1, D0D4B4, D0D4B6, D0D4B9, D0D4BA, D0D4BC, D0D4EF, D0D4F2, D0D4F5, D0D4F7, D0D4FB, D0D4FD, D0D501, D0D502, D0D504, D0D505, D0D507
- D0D624: D0D638, D0D63B
- D0D5F3: D0D60B

The successful primary artifacts and their ten model modules are now frozen. The supplemental checker is `tools/event_menu_text_tick_guard.py`; it targets row wrapping, offset equality, weapon rank clamping/late selected entries, absent/small/other object records, high shop-item bytes, FE/FF inventory sentinels, equipment without preview, consumable six and the object second-line early return. Vblank, palette/script drivers and subsequent navigation/icon models remain separately mutable and unverified.

Primary artifact SHA-256:

- `tools/event_menu_dialogue_setup.py`: `66eda01910c3bfe22cfccd52a198994b3294179413043211c69006e23670fa72`
- `tools/event_menu_equipment_selection.py`: `72a16adc8934915b177bfaa98a316fc2d1c1c4d1ad3c7bb7ba395cda450f8ac5`
- `tools/event_menu_description_script.py`: `52f44911133b354d17f3eee1c867c05e04a1382915bf5c1e3096decbe5271a30`
- `tools/event_menu_number_glyphs.py`: `bb1fe0307c87403177ed716cc9628070eaed3e539e2d1b58aa1379894d313509`
- `tools/event_menu_description_tables.py`: `e3d75449e6f5610b25aace3eb4ab3cebe0688008b68d36471d3693cd83bf6dfd`
- `tools/event_menu_equipment_predicates.py`: `74237af02f2b0564a94e2a4d5edbaeec724ae6bd76b2c3361e0a66ebcc3baeb3`
- `tools/event_menu_description_stats.py`: `c7cdf0d305567c0389e62326f4a51350fa9fc8e1e2699a83e665f06dee003976`
- `tools/event_menu_description_prices.py`: `b1037ee7a230e427e82e0067677c9ded809a7ec1bb9624e1b02873c370e8a28e`
- `tools/event_menu_description_render.py`: `68a6c5fdcfaffc7aac36f87b5bce0551fdbbb4e976b32be1b4217d51e8ddb3ad`
- `tools/event_menu_text_tick.py`: `84fdcf53ccc6f47665b661245274998de62929415358d571a546fe05b56025c1`
- `tools/event_menu_text_tick_check.py`: `027ec81f2a04d6967a23ad6213346b16d155be51caf1b063a42c565528934db1`
- `data/event_menu_text_tick.json`: `3406d6874bb7629047c05d20c0c9386c9da2f7a5337ba269a26dc22b0aeb98eb`
- `data/event_menu_text_tick.coverage.json`: `21675dfd131abbbb2fee71478597c222b86c560de9796b16caa59c2e1092658b`

## Directed supplement and complete source evidence

The separate 15-call original supplement passed on its first capture; none of the successful primary model, checker, report or capture files changed. Combined evidence now observes **1,003/1,003 instruction starts across all 37 bodies**, with all immediate widths and body boundaries accepted by source recovery. The union contains 1,795 PC/M/X states. The primary partial audit is preserved as its own evidence; the complete union audit is `data/event_menu_text_tick.complete_source_audit.json`.

The supplemental shop branch uses an actual runtime D8 byte at a native nonnegative word index, without asserting that every possible shop index is produced by game data. Its other cases use explicit menu fields to exercise the missing branch contracts. No asset, ROM table, text or script payload is persisted. No synthetic return, empty guard or hook substitutes for a callee.

Integration spec: `event_menu_text_tick_check:EventMenuTextTick:event-menu-text-tick:event_menu_text_tick`, with supplemental validation from `event_menu_text_tick_guard.py` and `data/event_menu_text_tick_guard.coverage.json`. The 2,155 bytes are candidates for new source credit only after physical-overlap review and independent exact assembly. Vblank/interactive menu drivers remain outside this result.

Supplemental frozen artifact SHA-256:

- `tools/event_menu_text_tick_guard.py`: `db355cbd80fd79e89a24be7150285cbe8165175c4f89c12edbd5377d11f43c35`
- `data/event_menu_text_tick_guard.json`: `422a60747662cae8066a01f3231c6c45f9fcb88eba75a152b4968f4e8c27ea21`
- `data/event_menu_text_tick_guard.coverage.json`: `694ff6cd4defdea40174be56b553cfe100f8abe63311b542f89bbfb3e8e9b4c1`
- `data/event_menu_text_tick.complete_source_audit.json`: `3fb636abe041168cfed2b1af304e0b00eb6b05ad347f2359fc20e7c805e11b81`
