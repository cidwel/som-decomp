; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-secondary-resources.md.
.setcpu "65816"
.smart
.a8
.i16

enter_warm_runtime_and_call_brightness_fade = $95E8

.segment "CODE"
.org $935D
call_warm_scene_runtime:
    jsr enter_warm_runtime_and_call_brightness_fade
