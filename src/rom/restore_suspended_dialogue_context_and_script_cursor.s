; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-line-completion.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_dialogue_window_cursor_and_render_state = $193F
select_dialogue_window_geometry_from_state = $0D8B

.segment "CODE"
.org $0F2C
restore_suspended_dialogue_context_and_script_cursor:
    phb
    .a8
    lda #$7E
    pha
    plb
    lda a:$A162
    .a8
    cmp #$02
    bne restore_suspended_dialogue_context_and_script_cursor_c00f57
    lda a:$A188
    sta f:$7EA162
    jsr select_dialogue_window_geometry_from_state
    jsr initialize_dialogue_window_cursor_and_render_state
    rep #$20
    lda a:$A1D1
    sta f:$001D01
    sep #$20
    lda a:$A1D3
    sta f:$001D03
restore_suspended_dialogue_context_and_script_cursor_c00f57:
    plb
    rts
