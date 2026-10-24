; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $F256
map_piece_dimension_headers_20261013_cef256:
    .byte ((30 - 1) * 2) | 1
    .byte ((40 - 1) * 2) | 0
