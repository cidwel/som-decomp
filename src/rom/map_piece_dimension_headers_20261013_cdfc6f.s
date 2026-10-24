; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $FC6F
map_piece_dimension_headers_20261013_cdfc6f:
    .byte ((48 - 1) * 2) | 1
    .byte ((48 - 1) * 2) | 0
