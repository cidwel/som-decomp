; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $3000
map_piece_dimension_headers_20261013_cc3000:
    .byte ((36 - 1) * 2) | 0
    .byte ((36 - 1) * 2) | 0
