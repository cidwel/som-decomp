; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

append_native_menu_digit_with_leading_zero_suppression = $D7FD

.segment "CODE"
.org $D8C6
emit_one_menu_price_digit_by_repeated_word_subtraction:
    pha
    tya
    .i16
    ldy #$FFFF
emit_one_menu_price_digit_by_repeated_word_subtraction_d0d8cb:
    iny
    sec
    sbc $01,S
    bcs emit_one_menu_price_digit_by_repeated_word_subtraction_d0d8cb
    clc
    adc $01,S
    sta $01,S
    tya
    ply
    jsr append_native_menu_digit_with_leading_zero_suppression
    rep #$20
    rts
