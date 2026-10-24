; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-child-resources.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B949
enter_first_warm_graphics_child:
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
