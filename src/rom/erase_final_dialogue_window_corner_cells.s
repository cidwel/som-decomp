; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-close.md.
.setcpu "65816"
.smart
.a8
.i16

exchange_dialogue_tilemap_entry_with_zero_tile = $1BBD

.segment "CODE"
.org $089E
erase_final_dialogue_window_corner_cells:
    lda a:$A166
    sta a:$A157
    lda a:$A165
    sta a:$A156
    jsr exchange_dialogue_tilemap_entry_with_zero_tile
    inc a:$A156
    jsr exchange_dialogue_tilemap_entry_with_zero_tile
    inc a:$A157
    jsr exchange_dialogue_tilemap_entry_with_zero_tile
    dec a:$A156
    jsr exchange_dialogue_tilemap_entry_with_zero_tile
    inc a:$A15E
    rts
