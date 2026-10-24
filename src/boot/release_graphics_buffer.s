; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_b0d6 = $B0D6
release_matching_vram_tag = $D678
select_graphics_registration = $805F

.segment "CODE"
.org $81AA
release_graphics_buffer:
    phd
    php
    rep #$30
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    jsr select_graphics_registration
    tax
    ldy a:$0006,X
    stz a:$0006,X
    lda a:$0000,X
    stz a:$0000,X
    tyx
    pha
    jsr boot_b0d6
    pla
    jsr release_matching_vram_tag
    plb
    plp
    pld
    rts
