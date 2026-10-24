; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $DDB1
map_piece_dimension_headers_20261013_ceddb1:
    .byte ((32 - 1) * 2) | 0
    .byte ((40 - 1) * 2) | 0
