; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $1E2A
map_piece_dimension_headers_20261013_cf1e2a:
    .byte ((64 - 1) * 2) | 0
    .byte ((48 - 1) * 2) | 0
