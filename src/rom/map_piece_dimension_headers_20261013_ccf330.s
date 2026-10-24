; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $F330
map_piece_dimension_headers_20261013_ccf330:
    .byte ((50 - 1) * 2) | 1
    .byte ((52 - 1) * 2) | 0
