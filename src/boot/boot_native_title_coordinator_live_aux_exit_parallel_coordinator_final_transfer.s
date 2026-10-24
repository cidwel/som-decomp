; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-final-transfer.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00d48d = $D48D
routine_7ed40d = $D40D

.segment "CODE"
.org $D4EE
repeat_title_after_actual_outer_zero:
    jsr routine_7ed40d
    .a8
    cmp #$00
    bne routine_00d48d
