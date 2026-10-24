; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-scroll.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_scrolling_dialogue_sprite_workspace_long = $C10030

.segment "CODE"
.org $0AA1
publish_scrolling_dialogue_sprite_graphics:
    jsl f:initialize_scrolling_dialogue_sprite_workspace_long
    stz a:$A161
    .i16
    ldx #$0000
    .i16
    ldy #$0000
    .a8
    lda #$04
    sta a:$A175
publish_scrolling_dialogue_sprite_graphics_cc0ab3:
    .a8
    lda #$20
publish_scrolling_dialogue_sprite_graphics_cc0ab5:
    xba
    lda f:$DCFF80,X
    sta a:$9400,Y
    inx
    iny
    xba
    dec
    bne publish_scrolling_dialogue_sprite_graphics_cc0ab5
    phx
    .a8
    lda #$00
    .i16
    ldx #$0020
publish_scrolling_dialogue_sprite_graphics_cc0ac9:
    sta a:$9400,Y
    iny
    dex
    bne publish_scrolling_dialogue_sprite_graphics_cc0ac9
    plx
    dec a:$A175
    bne publish_scrolling_dialogue_sprite_graphics_cc0ab3
    sta a:$9400,Y
    .a8
    lda #$05
    sta a:$1D11
    lda f:$001D04
    .a8
    ora #$04
    sta f:$001D04
    rep #$20
    lda f:$001D01
    inc
    inc
    sta f:$001D01
    sep #$20
    stz a:$A170
    .a8
    lda #$04
    sta f:$001D11
    rts
