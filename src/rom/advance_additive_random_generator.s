; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $38A0
advance_additive_random_generator:
    phx
    phy
    php
    sep #$10
    ldx a:$03F0
    lda a:$03F1,X
    sta $CC
    dex
    bpl advance_additive_random_generator_c038b2
    .i8
    ldx #$0E
advance_additive_random_generator_c038b2:
    lda a:$03F1,X
    clc
    adc $CC
    sta a:$03F1,X
    xba
    inc a:$03F0
    .a8
    lda #$0F
    cmp a:$03F0
    bne advance_additive_random_generator_c038c9
    stz a:$03F0
advance_additive_random_generator_c038c9:
    xba
    plp
    ply
    plx
    rts
