; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-settings-page.md.
.setcpu "65816"
.smart
.a8
.i16

clear_native_menu_sprite_tables_long_wrapper = $C02ACF
construct_native_menu_page_long_call_wrapper = $C02ACB
prepare_native_shop_tile_graphics_palettes_and_publication_flag = $60C7
publish_three_native_settings_color_cursor_coordinates = $6057
publish_three_native_shop_five_bit_icon_selectors = $6081
render_native_shop_item_tile_frame = $C76170
reset_native_menu_publication_long_wrapper = $C02AC7
routine_c02afa = $C02AFA
snapshot_controller_binding_words_and_normalize_runtime_mirror_bits = $C76FC2
snapshot_native_settings_selector_and_eight_icon_variants = $602B
upload_native_menu_sprite_tables_long_wrapper = $C02AD3

.segment "CODE"
.org $5FFD
construct_native_settings_page_and_snapshot_its_selectors:
    .a8
    lda #$02
    sta a:$A20F
    jsl f:snapshot_controller_binding_words_and_normalize_runtime_mirror_bits
    jsl f:render_native_shop_item_tile_frame
    jsl f:construct_native_menu_page_long_call_wrapper
    jsr prepare_native_shop_tile_graphics_palettes_and_publication_flag
    jsl f:routine_c02afa
    jsl f:clear_native_menu_sprite_tables_long_wrapper
    jsr publish_three_native_shop_five_bit_icon_selectors
    jsr publish_three_native_settings_color_cursor_coordinates
    jsl f:upload_native_menu_sprite_tables_long_wrapper
    jsl f:reset_native_menu_publication_long_wrapper
    jsr snapshot_native_settings_selector_and_eight_icon_variants
    rtl
