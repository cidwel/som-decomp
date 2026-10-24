; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D7FD
append_native_menu_digit_with_leading_zero_suppression:
    sep #$20
    pha
    .a8
    lda #$10
    bit a:$1802
    bne append_native_menu_digit_with_leading_zero_suppression_d0d816
    lda $01,S
    bne append_native_menu_digit_with_leading_zero_suppression_d0d811
    .a8
    lda #$80
    sta $01,S
    bra append_native_menu_digit_with_leading_zero_suppression_d0d816
append_native_menu_digit_with_leading_zero_suppression_d0d811:
    .a8
    lda #$10
    tsb a:$1802
append_native_menu_digit_with_leading_zero_suppression_d0d816:
    pla
    .a8
    bit #$80
    bne append_native_menu_digit_with_leading_zero_suppression_d0d81e
    clc
    .a8
    adc #$B5
append_native_menu_digit_with_leading_zero_suppression_d0d81e:
    sta $00,X
    inx
    rts
