; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-pause.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $0F08
save_dialogue_cursor_before_temporary_window:
    lda f:$7EA162
    .a8
    cmp #$02
    beq save_dialogue_cursor_before_temporary_window_c00f2b
    rep #$20
    lda f:$001D01
    inc
    sta a:$A1D1
    sep #$20
    lda f:$001D03
    sta a:$A1D3
    lda f:$7EA162
    sta f:$7EA188
save_dialogue_cursor_before_temporary_window_c00f2b:
    rts
