; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $EC5C
map_piece_dimension_headers_20261013_cdec5c:
    .byte ((64 - 1) * 2) | 0
    .byte ((64 - 1) * 2) | 0
