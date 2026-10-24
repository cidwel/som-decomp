; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $26F9
copy_boss_palette_with_cpu_words:
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
    sta $79
    .a16
    lda #$C200
    sta $77
    tya
    asl
    tax
    lda f:$D0BB24,X
    sta $76
    .i16
    ldy #$0000
copy_boss_palette_with_cpu_words_c22720:
    lda [$76],Y
    sta ($79),Y
    iny
    iny
    .i16
    cpy #$0020
    bcc copy_boss_palette_with_cpu_words_c22720
    rts
