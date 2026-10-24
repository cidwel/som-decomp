; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $1DF6
map_piece_dimension_headers_20261013_cd1df6:
    .byte ((40 - 1) * 2) | 1
    .byte ((48 - 1) * 2) | 0
