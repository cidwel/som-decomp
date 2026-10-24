; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-secondary-resources.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eabe7 = $ABE7

.segment "CODE"
.org $CB2B
enter_second_warm_colour_decay_and_suspend_long_timer:
    phd
    php
    rep #$30
    sep #$20
    .i16
    ldx #$0168
    jsr routine_7eabe7
