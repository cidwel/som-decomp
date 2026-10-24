; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-number-window.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $193F
initialize_dialogue_window_cursor_and_render_state:
    .i16
    ldx #$4910
    lda f:$001D05
    .a8
    cmp #$07
    bne initialize_dialogue_window_cursor_and_render_state_c01957
    .i16
    ldx #$65A0
    lda a:$A162
    .a8
    cmp #$01
    beq initialize_dialogue_window_cursor_and_render_state_c01957
    .i16
    ldx #$6590
initialize_dialogue_window_cursor_and_render_state_c01957:
    stx a:$A18C
    .i16
    ldx #$0122
    lda a:$A162
    .a8
    cmp #$02
    bne initialize_dialogue_window_cursor_and_render_state_c01967
    .i16
    ldx #$01E0
initialize_dialogue_window_cursor_and_render_state_c01967:
    stx a:$A17E
    lda a:$A197
    sta a:$A17D
    lda a:$A196
    sta a:$A17C
    stz a:$A180
    stz a:$A15D
    stz a:$A181
    stz a:$A186
    .i16
    ldx #$9000
    stx a:$A189
    lda a:$A16C
    sta a:$A193
    .a8
    lda #$68
    sta a:$A15B
    .a8
    lda #$48
    sta a:$A19F
    rts
