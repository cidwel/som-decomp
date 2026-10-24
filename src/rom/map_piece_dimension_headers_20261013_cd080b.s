; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $080B
map_piece_dimension_headers_20261013_cd080b:
    .byte ((24 - 1) * 2) | 0
    .byte ((20 - 1) * 2) | 0
