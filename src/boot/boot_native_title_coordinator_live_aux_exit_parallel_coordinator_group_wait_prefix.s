; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-group-wait-prefix.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7ed17f = $D17F

.segment "CODE"
.org $D4D2
enter_group_wait_after_actual_constructor_return:
    .i16
    ldx #$012C
    jsr routine_7ed17f
