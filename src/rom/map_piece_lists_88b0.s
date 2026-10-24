; Bounded native map piece lists; docs/map-piece-list-numeric.md.
.setcpu "65816"
.segment "CODE"
.org $88B0
.macro map_piece flag_index, flag_min, flag_max, piece_id, tile_x, tile_y
    .byte flag_index, (flag_min << 4) | flag_max, piece_id & $FF
    .byte (tile_x << 1) | ((piece_id >> 8) & 1)
    .byte (tile_y << 1) | ((piece_id >> 9) & 1)
.endmacro
map_1E8_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 439, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 439, 0, 0
map_1E9_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 439, 0, 0
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 439, 0, 0
map_1EF_piece_list:
    .byte $FE ; initialize layer 1
    map_piece 0, 0, 15, 130, 0, 0
    map_piece 0, 0, 15, 234, 12, 7
    map_piece 0, 0, 15, 234, 17, 7
    map_piece 0, 0, 15, 234, 20, 9
    map_piece 0, 0, 15, 234, 9, 9
    map_piece 0, 0, 15, 138, 14, 6
    map_piece 0, 0, 15, 130, 0, 29
    .byte $FF ; initialize layer 2
    map_piece 0, 0, 15, 131, 0, 0
    map_piece 0, 0, 15, 139, 14, 6
