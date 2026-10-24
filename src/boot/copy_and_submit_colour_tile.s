; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_graphics_workspace_block = $81D6
boot_b081 = $B081
copy_far_stack_arguments = $C44E
queue_single_graphics_block = $82D4

.segment "CODE"
.org $BF2A
copy_and_submit_colour_tile:
    phd
    php
    rep #$30
    pha
    tsc
    tcd
    pla
    phx
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    .i16
    ldy #$0040
    phy
    pha
    phx
    tyx
    jsr boot_b081
    stx $01
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
    .a8
    lda #$43
    jsr allocate_graphics_workspace_block
    .a8
    lda #$FF
    xba
    .a8
    lda #$7F
    ldy $01
    jsr queue_single_graphics_block
    plb
    pla
    pla
    plp
    pld
    rts
