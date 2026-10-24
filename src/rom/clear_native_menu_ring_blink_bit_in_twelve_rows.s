; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-action-rows.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7908
clear_native_menu_ring_blink_bit_in_twelve_rows:
    rep #$30
    .i16
    ldx #$0000
clear_native_menu_ring_blink_bit_in_twelve_rows_c0790d:
    lda a:$18C0,X
    .a16
    and #$FF7F
    sta a:$18C0,X
    txa
    clc
    .a16
    adc #$0010
    tax
    .i16
    cpx #$00C0
    bcc clear_native_menu_ring_blink_bit_in_twelve_rows_c0790d
    rts
