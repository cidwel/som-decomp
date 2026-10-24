; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-child-animation.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BA01
enter_warm_child_animation_loop:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    stx $01
