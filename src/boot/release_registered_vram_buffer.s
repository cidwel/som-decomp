; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

boot_b0d6 = $B0D6
find_registered_vram_buffer = $C73B
release_matching_vram_tag = $D678

.segment "CODE"
.org $C826
release_registered_vram_buffer:
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
    jsr find_registered_vram_buffer
    stx $01
    ldy a:$0002,X
    stz a:$0002,X
    tyx
    jsr boot_b0d6
    ldx $01
    lda a:$0000,X
    stz a:$0000,X
    jsr release_matching_vram_tag
    plb
    sep #$20
    pla
    pla
    plp
    pld
    rts
