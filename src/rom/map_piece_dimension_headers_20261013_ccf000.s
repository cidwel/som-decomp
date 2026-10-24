; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $F000
map_piece_dimension_headers_20261013_ccf000:
    .byte ((31 - 1) * 2) | 0
    .byte ((30 - 1) * 2) | 0
