; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-warm-child-launch.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7eabe7 = $ABE7

.segment "CODE"
.org $958A
suspend_warm_scene_initializer_for_one_receive:
    .i16
    ldx #$0001
    jsr routine_7eabe7
