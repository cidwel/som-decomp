; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-latent-scroll-flow.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c9ffce = $FFCE

.segment "CODE"
.org $FE17
latent_parse_scrolling_dialogue_line_commands:
    jsr routine_c9ffce
    ldx a:$A18F
    stx a:$A19B
    ldy a:$A173
latent_parse_scrolling_dialogue_line_commands_c9fe23:
    .a8
    lda #$00
    xba
    lda a:$9000,Y
    sec
    .a8
    sbc #$7C
    bcs latent_parse_scrolling_dialogue_line_commands_c9fe30
    .a8
    lda #$04
latent_parse_scrolling_dialogue_line_commands_c9fe30:
    asl
    tax
    jsr ($FFEF,X)
    bcc latent_parse_scrolling_dialogue_line_commands_c9fe23
    sty a:$A173
    .a8
    lda #$03
    sta a:$A20C
    lda f:$001D04
    .a8
    ora #$44
    sta f:$001D04
    inc a:$A161
    rts
