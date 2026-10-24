; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-pause.md.
.setcpu "65816"
.smart
.a8
.i16

save_dialogue_cursor_before_temporary_window = $0F08

.segment "CODE"
.org $0F7D
save_cursor_and_mark_temporary_dialogue_state:
    jsr save_dialogue_cursor_before_temporary_window
    .a8
    lda #$02
    sta f:$7EA162
    rts
