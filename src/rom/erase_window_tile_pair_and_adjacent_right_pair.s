; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-state.md.
.setcpu "65816"
.smart
.a8
.i16

exchange_dialogue_tilemap_entry_and_request_upload = $1BC0
exchange_dialogue_tilemap_entry_with_zero_tile = $1BBD

.segment "CODE"
.org $0B36
erase_window_tile_pair_and_adjacent_right_pair:
    jsr exchange_dialogue_tilemap_entry_with_zero_tile
    inc a:$A157
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    dec a:$A157
    inc a:$A156
    jsr exchange_dialogue_tilemap_entry_with_zero_tile
    inc a:$A157
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    rts
