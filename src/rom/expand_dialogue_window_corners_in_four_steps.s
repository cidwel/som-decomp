; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-state.md.
.setcpu "65816"
.smart
.a8
.i16

exchange_dialogue_tilemap_entry_and_request_upload = $1BC0

.segment "CODE"
.org $0A8D
expand_dialogue_window_corners_in_four_steps:
    lda a:$A165
    sta a:$A156
    lda a:$A166
    sta a:$A157
    .i16
    ldx #$0120
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A156
    .i16
    ldx #$8120
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    dec a:$A157
    lda a:$A157
    sta a:$A166
    dec a:$A164
    beq expand_dialogue_window_corners_in_four_steps_c00b19
    .i16
    ldx #$8120
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    dec a:$A156
    .i16
    ldx #$0120
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    dec a:$A157
    lda a:$A157
    sta a:$A166
    dec a:$A164
    beq expand_dialogue_window_corners_in_four_steps_c00b19
    lda a:$A165
    sta a:$A156
    lda a:$A168
    sta a:$A157
    .i16
    ldx #$0120
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A156
    .i16
    ldx #$8120
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A157
    lda a:$A157
    sta a:$A168
    dec a:$A164
    beq expand_dialogue_window_corners_in_four_steps_c00b19
    .i16
    ldx #$8120
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    dec a:$A156
    .i16
    ldx #$0120
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A157
    lda a:$A157
    sta a:$A168
    dec a:$A164
    bne expand_dialogue_window_corners_in_four_steps_c00b1c
expand_dialogue_window_corners_in_four_steps_c00b19:
    inc a:$A15C
expand_dialogue_window_corners_in_four_steps_c00b1c:
    rts
