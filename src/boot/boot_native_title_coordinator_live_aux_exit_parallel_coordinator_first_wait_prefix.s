; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-first-wait-prefix.md.
.setcpu "65816"
.smart
.a8
.i16

routine_7ed17f = $D17F

.segment "CODE"
.org $D494
enter_first_title_wait_after_actual_nonzero_phase_return:
    .i16
    ldx #$0564
    jsr routine_7ed17f
