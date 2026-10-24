; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D678
release_matching_vram_tag:
    phd
    php
    rep #$30
    pha
    tsc
    inc
    tcd
    pla
    phb
    sep #$20
    phb
    pha
    .a8
    lda #$7F
    pha
    plb
    pla
    rep #$20
    .a16
    and #$00FF
    clc
    adc a:$032C
    tax
    sep #$20
    .a8
    lda #$20
    sta $01
    lda a:$0000,X
    ldx a:$032C
release_matching_vram_tag_d6a1:
    cmp a:$0000,X
    bne release_matching_vram_tag_d6a9
    stz a:$0000,X
release_matching_vram_tag_d6a9:
    inx
    dec $01
    bne release_matching_vram_tag_d6a1
    plb
    pla
    plp
    pld
    rts
