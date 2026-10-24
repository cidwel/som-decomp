; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

copy_far_stack_arguments = $C44E

.segment "CODE"
.org $991C
initialize_low_colour_scene_template:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$00
    pha
    plb
    .i16
    ldx #$0040
    phx
    .a8
    lda #$7E
    pha
    .i16
    ldx #$5FCA
    phx
    .a8
    lda #$00
    pha
    .i16
    ldx #$1D00
    phx
    jsr copy_far_stack_arguments
    rep #$20
    tsc
    clc
    .a16
    adc #$0008
    tcs
    sep #$20
    stz a:$1D40
    plb
    plp
    pld
    rts
