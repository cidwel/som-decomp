; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-number-window.md.
.setcpu "65816"
.smart
.a8
.i16

construct_temporary_numeric_dialogue_script = $1999
initialize_dialogue_window_cursor_and_render_state = $193F
save_dialogue_cursor_before_temporary_window = $0F08
select_dialogue_window_geometry_from_state = $0D8B

.segment "CODE"
.org $0F87
open_temporary_numeric_dialogue_window:
    jsr save_dialogue_cursor_before_temporary_window
    .a8
    lda #$02
    sta a:$A162
    jsr construct_temporary_numeric_dialogue_script
    jsr select_dialogue_window_geometry_from_state
    jsr initialize_dialogue_window_cursor_and_render_state
    .a8
    lda #$53
    sta a:$A170
    lda f:$001D00
    .a8
    ora #$04
    .a8
    and #$BF
    sta f:$001D00
    rts
