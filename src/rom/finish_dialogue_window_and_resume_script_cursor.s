; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-render-core.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_dialogue_window_cursor_and_render_state = $193F

.segment "CODE"
.org $06A8
finish_dialogue_window_and_resume_script_cursor:
    jsr initialize_dialogue_window_cursor_and_render_state
    stz a:$A15F
    .a8
    lda #$00
    stz a:$A170
    lda f:$001D00
    .a8
    and #$10
    pha
    bne finish_dialogue_window_and_resume_script_cursor_c006c9
    rep #$20
    lda f:$001D01
    inc
    sta f:$001D01
    sep #$20
finish_dialogue_window_and_resume_script_cursor_c006c9:
    pla
    .a8
    and #$EE
    sta f:$001D00
    stz a:$A15F
    stz a:$A15C
    stz a:$A16F
    rts
