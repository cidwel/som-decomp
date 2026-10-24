; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-blend.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $159E
select_dialogue_background_mask_from_style_list:
    .i16
    ldy #$9400
    .a8
    lda #$00
    xba
    lda f:$7EA24E
    tax
    lda f:$7EA24F,X
    xba
    .a8
    lda #$00
    rep #$20
    lsr
    sta a:$A182
    sep #$20
    rts
