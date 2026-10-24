; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $54B6
multiply_byte_by_word:
    lda $D0
    sta f:$004202
    lda $D4
    sta f:$004203
    rep #$20
    stz $CD
    nop
    nop
    lda f:$004216
    sta $CC
    sep #$20
    lda $D5
    sta f:$004203
    rep #$20
    nop
    nop
    nop
    lda f:$004216
    clc
    adc $CD
    sta $CD
    sep #$20
    rts
