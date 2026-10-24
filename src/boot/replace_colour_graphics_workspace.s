; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_graphics_workspace_block = $81D6
create_graphics_buffer = $809B
release_graphics_buffer = $81AA

.segment "CODE"
.org $BEDD
replace_colour_graphics_workspace:
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
    rep #$20
    stx $01
    .a16
    lda #$0043
    jsr release_graphics_buffer
    .a16
    lda #$0043
    .i16
    ldx #$0300
    jsr create_graphics_buffer
replace_colour_graphics_workspace_befe:
    .a16
    lda #$0043
    jsr allocate_graphics_workspace_block
    dec $01
    bne replace_colour_graphics_workspace_befe
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
