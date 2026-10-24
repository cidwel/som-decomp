; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16

copy_dialogue_style_palette_and_highlight_colors = $0DFC

.segment "CODE"
.org $05C3
publish_active_dialogue_window_style_palette_pair:
    .a8
    lda #$00
    xba
    lda a:$A24E
    tax
    phx
    lda f:$C77161,X
    rep #$20
    asl
    sta a:$A173
    asl
    clc
    adc a:$A173
    tay
    .i16
    ldx #$01E0
    sep #$20
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
    ldx #$01E8
    sep #$20
    jsr copy_dialogue_style_palette_and_highlight_colors
    rep #$20
    pla
    asl
    tax
    lda a:$A23E,X
    sta f:$0007E4
    sep #$20
    rts
