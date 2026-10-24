; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $14F0
map_piece_dimension_headers_20261013_cc14f0:
    .byte ((42 - 1) * 2) | 0
    .byte ((63 - 1) * 2) | 0
