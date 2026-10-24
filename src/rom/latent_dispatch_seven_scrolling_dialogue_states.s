; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-latent-scroll-flow.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FD80
latent_dispatch_seven_scrolling_dialogue_states:
    phb
    .a8
    lda #$7E
    pha
    plb
    .a8
    lda #$7D
    sta a:$A170
    .a8
    lda #$01
    sta f:$001D11
    .a8
    lda #$00
    xba
    lda a:$A161
    asl
    tax
    jsr ($FFE1,X)
    plb
    rtl
