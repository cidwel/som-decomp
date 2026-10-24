; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-pause.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c00f86 = $0F86
save_cursor_and_mark_temporary_dialogue_state = $0F7D

.segment "CODE"
.org $0F59
request_dialogue_secondary_window_pause:
    .a8
    lda #$51
    sta a:$A170
    lda a:$A187
    .a8
    and #$01
    bne save_cursor_and_mark_temporary_dialogue_state
    .a8
    lda #$04
    sta a:$A15E
    bra routine_c00f86
