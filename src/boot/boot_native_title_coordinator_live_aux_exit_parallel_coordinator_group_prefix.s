; Recovered Secret of Mana USA routine; behaviour documented in docs/boot-native-title-coordinator-live-aux-exit-parallel-coordinator-group-prefix.md.
.setcpu "65816"
.smart
.a8
.i16

routine_00d4f5 = $D4F5
routine_7ed051 = $D051

.segment "CODE"
.org $D4C3
enter_first_group_after_actual_expansion_return:
    .a8
    cmp #$00
    beq routine_00d4f5
    .a8
    lda #$02
    sta $01
    .a8
    lda #$03
    sta $02
    jsr routine_7ed051
