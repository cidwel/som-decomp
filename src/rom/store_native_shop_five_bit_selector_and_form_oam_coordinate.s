; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-shop-records.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $60BA
store_native_shop_five_bit_selector_and_form_oam_coordinate:
    .a16
    and #$001F
    sta a:$A1D1,X
    inx
    asl
    clc
    .a16
    adc #$00A7
    rts
