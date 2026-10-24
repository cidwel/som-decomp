; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-latent-scroll-flow.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c10014 = $C10014
routine_c9ff80 = $FF80

.segment "CODE"
.org $FD9D
latent_initialize_scrolling_dialogue_graphics_and_script:
    .a8
    lda #$7E
    xba
    .a8
    lda #$C7
    .i16
    ldx #$C1C0
    .i16
    ldy #$9400
    jsl f:routine_c10014
    rep #$20
    .a16
    lda #$4800
    sta f:$001D06
    .a16
    lda #$0400
    sta f:$001D08
    .a16
    lda #$0800
    sta f:$001D1A
    sep #$20
    lda f:$001D04
    .a8
    ora #$07
    sta f:$001D04
    .i16
    ldx #$0002
    stx a:$A18F
    jsr routine_c9ff80
    inc a:$A161
    rts
