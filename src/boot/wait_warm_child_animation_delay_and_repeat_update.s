; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-secondary-resources.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00ba0c = $BA0C
routine_7eabe7 = $ABE7

.segment "CODE"
.org $BA11
wait_warm_child_animation_delay_and_repeat_update:
    ldx $01
    ldy a:$0014,X
    tyx
    jsr routine_7eabe7
    bra routine_00ba0c
