; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $26AC
load_boss_palette_through_wram_dma:
    sep #$20
    sta a:$033F,X
    rep #$20
    tay
    txa
    .a16
    and #$000F
    xba
    lsr
    lsr
    lsr
    clc
    .a16
    adc #$0600
    sta f:$002181
    tya
    asl
    tax
    lda f:$D0BB24,X
    sta f:$004372
    .a16
    lda #$0020
    sta f:$004375
    sep #$20
    .a8
    lda #$00
    sta f:$002183
    .a8
    lda #$00
    sta f:$004370
    .a8
    lda #$80
    sta f:$004371
    .a8
    lda #$C2
    sta f:$004374
    .a8
    lda #$80
    sta f:$00420B
    rep #$20
    rts
