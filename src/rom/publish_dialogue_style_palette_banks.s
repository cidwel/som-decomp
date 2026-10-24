; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-blend.md.
.setcpu "65816"
.smart
.a8
.i16

copy_dialogue_style_palette_and_highlight_colors = $0DFC

.segment "CODE"
.org $0968
publish_dialogue_style_palette_banks:
    .a8
    lda #$00
    xba
    lda a:$A24E
    tax
    lda f:$C77161,X
    rep #$20
    asl
    sta a:$A173
    asl
    clc
    adc a:$A173
    tay
    sep #$20
    .i16
    ldx #$0000
    phy
    jsr copy_dialogue_style_palette_and_highlight_colors
    .a8
    lda #$00
    xba
    lda a:$A24E
    tax
    lda f:$C77159,X
    rep #$20
    asl
    sta a:$A173
    asl
    clc
    adc a:$A173
    tay
    .i16
    ldx #$0008
    sep #$20
    jsr copy_dialogue_style_palette_and_highlight_colors
    ply
    .i16
    ldx #$0010
    jsr copy_dialogue_style_palette_and_highlight_colors
    rep #$20
    .a16
    lda #$7C1F
    sta f:$000616
    sep #$20
    rts
