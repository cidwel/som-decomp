; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-state.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_dialogue_window_cursor_and_render_state = $193F
restore_suspended_dialogue_context_and_script_cursor = $0F2C

.segment "CODE"
.org $0D51
finish_dialogue_window_frame_and_restore_suspended_script:
    stz a:$A15C
    jsr initialize_dialogue_window_cursor_and_render_state
    stz a:$A170
    lda f:$001D00
    .a8
    and #$FA
    sta f:$001D00
    lda f:$001D10
    .a8
    and #$FC
    sta f:$001D10
    rep #$20
    lda f:$001D01
    inc
    sta f:$001D01
    sep #$20
    jsr restore_suspended_dialogue_context_and_script_cursor
    rts
