; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-title-hdma-resources.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_128_byte_units = $AF59

.segment "CODE"
.org $B081
allocate_boot_heap_bytes_without_fill:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    txa
    clc
    .a16
    adc #$007F
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    lsr
    jsr allocate_128_byte_units
    plb
    plp
    pld
    rts
