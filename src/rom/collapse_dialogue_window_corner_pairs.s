; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-close.md.
.setcpu "65816"
.smart
.a8
.i16

erase_window_tile_pair_and_adjacent_left_pair = $0B1D
erase_window_tile_pair_and_adjacent_right_pair = $0B36

.segment "CODE"
.org $0844
collapse_dialogue_window_corner_pairs:
    lda a:$A166
    sta a:$A157
    lda a:$A165
    sta a:$A156
    jsr erase_window_tile_pair_and_adjacent_right_pair
    inc a:$A166
    dec a:$A164
    beq collapse_dialogue_window_corner_pairs_c0089a
    lda a:$A168
    sta a:$A157
    dec a:$A156
    jsr erase_window_tile_pair_and_adjacent_left_pair
    dec a:$A168
    dec a:$A164
    beq collapse_dialogue_window_corner_pairs_c0089a
    lda a:$A166
    sta a:$A157
    lda a:$A165
    sta a:$A156
    jsr erase_window_tile_pair_and_adjacent_right_pair
    inc a:$A166
    dec a:$A164
    beq collapse_dialogue_window_corner_pairs_c0089a
    lda a:$A168
    sta a:$A157
    dec a:$A156
    jsr erase_window_tile_pair_and_adjacent_left_pair
    dec a:$A168
    dec a:$A164
    bne collapse_dialogue_window_corner_pairs_c0089d
collapse_dialogue_window_corner_pairs_c0089a:
    inc a:$A15E
collapse_dialogue_window_corner_pairs_c0089d:
    rts
