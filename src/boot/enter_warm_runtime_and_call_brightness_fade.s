; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-secondary-resources.md.
.setcpu "65816"
.smart
.a8
.i16

enter_warm_brightness_fade_and_suspend_first_timer = $95C0

.segment "CODE"
.org $95E8
enter_warm_runtime_and_call_brightness_fade:
    phd
    php
    rep #$30
    phx
    tsc
    tcd
    sep #$20
    jsr enter_warm_brightness_fade_and_suspend_first_timer
