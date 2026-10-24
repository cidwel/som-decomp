; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-action-rows.md.
.setcpu "65816"
.smart
.a8
.i16

hide_shop_hero_markers_before_price_selection = $C0793D

.segment "CODE"
.org $7922
clear_native_first_two_ring_rows_and_hide_hero_markers:
    rep #$30
    .i16
    ldx #$0000
clear_native_first_two_ring_rows_and_hide_hero_markers_c07927:
    .a16
    lda #$0000
    sta a:$18C0,X
    txa
    clc
    .a16
    adc #$0010
    tax
    .i16
    cpx #$001C
    bcc clear_native_first_two_ring_rows_and_hide_hero_markers_c07927
    jsl f:hide_shop_hero_markers_before_price_selection
    rts
