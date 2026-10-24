; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-actions.md.
.setcpu "65816"
.smart
.a8
.i16

native_menu_change_sound_long_wrapper = $C02AF2
prepare_native_shop_tile_graphics_palettes_and_publication_flag = $60C7
publish_three_native_shop_five_bit_icon_selectors = $6081
render_native_shop_item_tile_frame = $C76170

.segment "CODE"
.org $6256
refresh_native_shop_frame_graphics_icons_and_request_sound:
    jsl f:render_native_shop_item_tile_frame
    jsr prepare_native_shop_tile_graphics_palettes_and_publication_flag
    jsr publish_three_native_shop_five_bit_icon_selectors
    .a8
    lda #$06
    tsb a:$A20A
    jsl f:native_menu_change_sound_long_wrapper
    rtl
