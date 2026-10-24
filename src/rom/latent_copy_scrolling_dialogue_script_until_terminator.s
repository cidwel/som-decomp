; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-latent-scroll-flow.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FF80
latent_copy_scrolling_dialogue_script_until_terminator:
    .i16
    ldx #$0000
    stx a:$A173
    rep #$20
    lda f:$001D01
    tay
    sep #$20
    lda f:$001D03
    phb
    pha
    plb
    .i16
    ldx #$0000
latent_copy_scrolling_dialogue_script_until_terminator_c9ff99:
    lda a:$0000,Y
    sta f:$7E9000,X
    inx
    iny
    .a8
    cmp #$7E
    bne latent_copy_scrolling_dialogue_script_until_terminator_c9ff99
    .a8
    lda #$00
    sta f:$7E9000,X
    rep #$20
    tya
    sta f:$001D01
    sep #$20
    plb
    rts
