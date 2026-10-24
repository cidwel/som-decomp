; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-secondary-resources.md.
.setcpu "65816"
.smart
.a8
.i16

enter_second_warm_colour_decay_and_suspend_long_timer = $CB2B

.segment "CODE"
.org $CA4F
call_second_warm_scene_colour_decay_loop:
    jsr enter_second_warm_colour_decay_and_suspend_long_timer
