; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-window-state.md.
.setcpu "65816"
.smart
.a8
.i16

exchange_dialogue_tilemap_entry_and_request_upload = $1BC0
exchange_dialogue_tilemap_entry_with_zero_tile = $1BBD

.segment "CODE"
.org $0B1D
erase_window_tile_pair_and_adjacent_left_pair:
    jsr exchange_dialogue_tilemap_entry_with_zero_tile
    dec a:$A157
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    inc a:$A157
    inc a:$A156
    jsr exchange_dialogue_tilemap_entry_with_zero_tile
    dec a:$A157
    jsr exchange_dialogue_tilemap_entry_and_request_upload
    rts
