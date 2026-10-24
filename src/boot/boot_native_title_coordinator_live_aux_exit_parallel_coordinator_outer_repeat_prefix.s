; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-outer-repeat-prefix.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00d4cb = $D4CB
routine_00d4f5 = $D4F5

.segment "CODE"
.org $D4E6
repeat_outer_after_actual_intergroup_return:
    .a8
    cmp #$00
    beq routine_00d4f5
    dec $01
    bne routine_00d4cb
