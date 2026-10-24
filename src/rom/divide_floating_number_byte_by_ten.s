; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $84F9
divide_floating_number_byte_by_ten:
    sta f:$004204
    .a8
    lda #$00
    sta f:$004205
