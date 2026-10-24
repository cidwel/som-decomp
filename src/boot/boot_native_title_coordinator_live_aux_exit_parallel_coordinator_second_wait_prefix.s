; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-second-wait-prefix.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00d4f5 = $D4F5
routine_7ed17f = $D17F

.segment "CODE"
.org $D4B2
enter_second_wait_after_actual_scroll_return:
    .a8
    cmp #$00
    beq routine_00d4f5
    .i16
    ldx #$00C6
    jsr routine_7ed17f
