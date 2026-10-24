; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-scroll-transfer.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00d4f5 = $D4F5
routine_7ed348 = $D348

.segment "CODE"
.org $D4AB
enter_scroll_after_actual_title_hold_return:
    .a8
    cmp #$00
    beq routine_00d4f5
    jsr routine_7ed348
