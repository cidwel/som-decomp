; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-reveal-transfer.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00d4f5 = $D4F5
routine_7ed2fc = $D2FC

.segment "CODE"
.org $D49A
enter_title_reveal_after_actual_first_wait_completion:
    .a8
    cmp #$00
    beq routine_00d4f5
    jsr routine_7ed2fc
