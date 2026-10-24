; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scroll-countdown.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8113
decrement_wrapped_ten_bit_coordinate_and_six_bit_countdown:
    rep #$20
    lda $F6
    sec
    .a16
    sbc #$0010
    .a16
    and #$03FF
    sta $F6
    sep #$20
    lda $FE
    dec
    sta $FE
    .a8
    and #$3F
    beq decrement_wrapped_ten_bit_coordinate_and_six_bit_countdown_c0812c
    rts
decrement_wrapped_ten_bit_coordinate_and_six_bit_countdown_c0812c:
    .a8
    lda #$00
    sta $FE
    .a8
    lda #$20
    tsb $CC
    rep #$20
    lda $F6
    sec
    .a16
    sbc #$0010
    .a16
    and #$03FF
    sta $F6
    rts
