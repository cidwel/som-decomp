; Packed two-bit appearance attribute changes, applied with byte wrapping.
.setcpu "65816"
.segment "CODE"
.org $4B79
appearance_attribute_adjustment_table:
    .byte 0, 1, 5, 251
