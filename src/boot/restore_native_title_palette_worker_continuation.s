; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-palette-worker.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $D5B5
restore_native_title_palette_worker_continuation:
    phd
    php
    rep #$30
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    plb
    plp
    pld
    rtl
