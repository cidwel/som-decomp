; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $2E81
map_piece_dimension_headers_20261013_cd2e81:
    .byte ((32 - 1) * 2) | 0
    .byte ((24 - 1) * 2) | 0
