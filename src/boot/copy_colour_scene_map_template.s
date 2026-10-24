; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

copy_far_stack_arguments = $C44E

.segment "CODE"
.org $9763
copy_colour_scene_map_template:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    .i16
    ldy #$0100
    phy
    .a8
    lda #$7E
    pha
    .i16
    ldy #$50C0
    phy
    .a8
    lda #$7F
    pha
    phx
    jsr copy_far_stack_arguments
    rep #$20
    tsc
    clc
    .a16
    adc #$0008
    tcs
    sep #$20
    plb
    pla
    pla
    plp
    pld
    rts
