; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $B5CF
map_piece_dimension_headers_20261013_cdb5cf:
    .byte ((40 - 1) * 2) | 0
    .byte ((48 - 1) * 2) | 0
