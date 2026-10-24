; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-actions.md.
.setcpu "65816"
.smart
.a8
.i16

native_menu_change_sound_long_wrapper = $C02AF2
pack_three_native_shop_selectors_and_refresh_icon_oam = $62B8

.segment "CODE"
.org $6292
increment_native_shop_selector_unless_thirty_one:
    lda a:$A1D1,Y
    inc
    .a8
    cmp #$20
    beq increment_native_shop_selector_unless_thirty_one_c762a4
    sta a:$A1D1,Y
    jsr pack_three_native_shop_selectors_and_refresh_icon_oam
    jsl f:native_menu_change_sound_long_wrapper
increment_native_shop_selector_unless_thirty_one_c762a4:
    rtl
