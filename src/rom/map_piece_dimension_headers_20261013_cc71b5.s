; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $71B5
map_piece_dimension_headers_20261013_cc71b5:
    .byte ((64 - 1) * 2) | 0
    .byte ((64 - 1) * 2) | 0
