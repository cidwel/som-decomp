; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $6CC2
map_piece_dimension_headers_20261013_cc6cc2:
    .byte ((64 - 1) * 2) | 0
    .byte ((64 - 1) * 2) | 0
