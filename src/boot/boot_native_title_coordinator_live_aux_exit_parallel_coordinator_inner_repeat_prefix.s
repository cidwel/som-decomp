; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-inner-repeat-prefix.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00d4cf = $D4CF
routine_00d4f5 = $D4F5

.segment "CODE"
.org $D4D8
repeat_group_after_actual_first_timer_return:
    .a8
    cmp #$00
    beq routine_00d4f5
    dec $02
    bne routine_00d4cf
