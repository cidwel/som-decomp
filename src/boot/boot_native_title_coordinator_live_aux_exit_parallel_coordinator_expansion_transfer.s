; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-expansion-transfer.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00d4f5 = $D4F5
routine_7ed377 = $D377

.segment "CODE"
.org $D4BC
enter_expansion_after_actual_second_wait_return:
    .a8
    cmp #$00
    beq routine_00d4f5
    jsr routine_7ed377
