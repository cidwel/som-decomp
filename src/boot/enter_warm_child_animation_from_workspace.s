; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-child-animation.md.
.setcpu "65816"
.smart
.a8
.i16

enter_warm_child_animation_loop = $BA01

.segment "CODE"
.org $B95C
enter_warm_child_animation_from_workspace:
    stx $01
    ldx $01
    jsr enter_warm_child_animation_loop
