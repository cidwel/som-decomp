; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-actions.md.
.setcpu "65816"
.smart
.a8
.i16

native_menu_change_sound_long_wrapper = $C02AF2
pack_three_native_shop_selectors_and_refresh_icon_oam = $62B8

.segment "CODE"
.org $62A5
decrement_native_shop_selector_unless_zero:
    lda a:$A1D1,Y
    dec
    .a8
    cmp #$FF
    beq decrement_native_shop_selector_unless_zero_c762b7
    sta a:$A1D1,Y
    jsr pack_three_native_shop_selectors_and_refresh_icon_oam
    jsl f:native_menu_change_sound_long_wrapper
decrement_native_shop_selector_unless_zero_c762b7:
    rtl
