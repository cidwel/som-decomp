; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-intergroup-prefix.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7ed17f = $D17F

.segment "CODE"
.org $D4E0
enter_intergroup_wait_after_actual_inner_zero:
    .i16
    ldx #$012C
    jsr routine_7ed17f
