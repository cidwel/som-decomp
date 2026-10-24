; Recovered Secret of Mana USA routine; behaviour documented in docs/source-recovery-parallel-palette-apis.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BE01
read_native_palette_record_index_modulo_eight:
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
    sec
    sbc a:$02D2
    lsr
    lsr
    lsr
    lsr
    lsr
    .a16
    and #$0007
    plb
    plp
    pld
    rts
