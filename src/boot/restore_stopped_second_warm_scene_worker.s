; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-integrated-runtime.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $CA56
restore_stopped_second_warm_scene_worker:
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
