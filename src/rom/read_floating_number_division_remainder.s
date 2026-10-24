; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8503
read_floating_number_division_remainder:
    .a8
    lda #$0A
    sta f:$004206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lda f:$004216
    rts
