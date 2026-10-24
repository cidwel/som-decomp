; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-secondary-resources.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eabe7 = $ABE7

.segment "CODE"
.org $95C0
enter_warm_brightness_fade_and_suspend_first_timer:
    phd
    php
    rep #$30
    sep #$20
    .i16
    ldx #$0004
    jsr routine_7eabe7
