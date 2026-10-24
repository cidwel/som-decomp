; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-blend.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0DFC
copy_dialogue_style_palette_and_highlight_colors:
    phb
    .a8
    lda #$D2
    pha
    plb
    .a8
    lda #$06
copy_dialogue_style_palette_and_highlight_colors_c00e03:
    xba
    lda a:$DB80,Y
    sta f:$000602,X
    xba
    inx
    iny
    dec
    bne copy_dialogue_style_palette_and_highlight_colors_c00e03
    plb
    rep #$20
    lda a:$A24E
    .a16
    and #$00FF
    asl
    tax
    lda a:$A23E,X
    sta f:$000604
    sta f:$000614
    sep #$20
    rts
