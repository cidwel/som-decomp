; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-latent-scroll-flow.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c10030 = $C10030

.segment "CODE"
.org $FF21
latent_publish_scrolling_dialogue_sprite_graphics:
    jsl f:routine_c10030
    stz a:$A161
    .i16
    ldx #$0000
    .i16
    ldy #$0000
    .a8
    lda #$04
    sta a:$A175
latent_publish_scrolling_dialogue_sprite_graphics_c9ff33:
    .a8
    lda #$20
latent_publish_scrolling_dialogue_sprite_graphics_c9ff35:
    xba
    lda f:$DCFF80,X
    sta a:$9400,Y
    inx
    iny
    xba
    dec
    bne latent_publish_scrolling_dialogue_sprite_graphics_c9ff35
    phx
    .a8
    lda #$00
    .i16
    ldx #$0020
latent_publish_scrolling_dialogue_sprite_graphics_c9ff49:
    sta a:$9400,Y
    iny
    dex
    bne latent_publish_scrolling_dialogue_sprite_graphics_c9ff49
    plx
    dec a:$A175
    bne latent_publish_scrolling_dialogue_sprite_graphics_c9ff33
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
