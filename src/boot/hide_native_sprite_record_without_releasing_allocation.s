; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-hide-sprite-keep-allocation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B731
hide_native_sprite_record_without_releasing_allocation:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    .a16
    lda #$FFF0
    sta a:$0002,X
    stz a:$0004,X
    lda a:$000A,X
    .a16
    and #$00FF
    asl
    asl
    clc
    adc a:$02CC
    tax
    sep #$20
    .a8
    lda #$F0
    sta a:$0001,X
    plb
    plp
    pld
    rts
