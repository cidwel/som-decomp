; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $FF1A
map_piece_dimension_headers_20261013_cdff1a:
    .byte ((48 - 1) * 2) | 1
    .byte ((48 - 1) * 2) | 0
