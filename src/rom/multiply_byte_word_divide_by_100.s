; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $543B
multiply_byte_word_divide_by_100:
    stz $CE
    lda $A6
    sta f:$004202
    lda $A8
    sta f:$004203
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    sta $CC
    sep #$20
    lda $A9
    sta f:$004203
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    clc
    adc $CD
    sta $CD
    sta f:$004204
    sep #$20
    .a8
    lda #$64
    sta f:$004206
    stz $D0
    nop
    nop
    nop
    nop
    nop
    nop
    rep #$20
    lda f:$004214
    sta $D1
    sep #$20
    lda f:$004216
    xba
    lda $CC
    rep #$20
    sta f:$004204
    sep #$20
    .a8
    lda #$64
    sta f:$004206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    rep #$20
    lda f:$004214
    clc
    adc $D0
    sta $A4
    sep #$20
    rts
