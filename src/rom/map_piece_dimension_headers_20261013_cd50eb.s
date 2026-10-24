; Dimensions/low-bit subpiece flags only; following body excluded.
.setcpu "65816"
.segment "CODE"
.org $50EB
map_piece_dimension_headers_20261013_cd50eb:
    .byte ((26 - 1) * 2) | 1
    .byte ((28 - 1) * 2) | 0
