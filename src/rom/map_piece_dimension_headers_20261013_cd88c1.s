; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $88C1
map_piece_dimension_headers_20261013_cd88c1:
    .byte ((24 - 1) * 2) | 0
    .byte ((31 - 1) * 2) | 0
