; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $530E
map_piece_dimension_headers_20261013_cd530e:
    .byte ((28 - 1) * 2) | 1
    .byte ((32 - 1) * 2) | 0
