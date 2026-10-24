; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $F6CC
map_piece_dimension_headers_20261013_cef6cc:
    .byte ((64 - 1) * 2) | 0
    .byte ((64 - 1) * 2) | 0
