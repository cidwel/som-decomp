; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-state.md.
.setcpu "65816"
.smart
.a8
.i16

exchange_dialogue_tilemap_entry_and_request_upload = $1BC0
select_dialogue_window_geometry_from_state = $0D8B

.segment "CODE"
.org $0A34
initialize_dialogue_window_corner_pairs:
    jsr select_dialogue_window_geometry_from_state
    sta a:$A157
    sta a:$A166
    inc
    sta a:$A168
    xba
    sta a:$A156
    sta a:$A165
    inc
    sta a:$A167
    .i16
    ldx #$0120
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A156
    .i16
    ldx #$8120
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    dec a:$A156
    inc a:$A157
    .i16
    ldx #$4120
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A156
    .i16
    ldx #$C120
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A15C
    lda a:$A162
    .a8
    cmp #$01
    bne initialize_dialogue_window_corner_pairs_c00a8c
    .a8
    lda #$03
    sta a:$A15C
    lda a:$A196
    sta a:$A165
    lda a:$A197
    dec
    sta a:$A166
initialize_dialogue_window_corner_pairs_c00a8c:
    rts
