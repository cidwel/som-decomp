; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-secondary-resources.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $95E5
restore_warm_brightness_fade_and_return_to_scene_runtime:
    plp
    pld
    rts
