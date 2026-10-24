; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $2C23
map_piece_dimension_headers_20261013_cd2c23:
    .byte ((64 - 1) * 2) | 0
    .byte ((40 - 1) * 2) | 0
