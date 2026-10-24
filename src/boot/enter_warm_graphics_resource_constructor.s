; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-graphics-prefix.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $93F4
enter_warm_graphics_resource_constructor:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$0004
    tcd
    tcs
    .a16
    lda #$0082
    .i16
    ldx #$002E
