; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

release_graphics_buffer = $81AA
release_registered_vram_buffer = $C826

.segment "CODE"
.org $BF10
release_colour_scene:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    ldx a:$02D4
    jsr release_registered_vram_buffer
    .a8
    lda #$43
    jsr release_graphics_buffer
    plb
    plp
    pld
    rts
