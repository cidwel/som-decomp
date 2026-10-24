; Numeric cast descriptors only; no referenced script/graphics payload.
.setcpu "65816"
.segment "RODATA"
.org $2F60
ordinary_remaining_numeric_20261013_cast_13:
    .word $85FC ; hero actor script cursor
    .word $05F4, $05F4, $05F4 ; packed graphics resource parameters
    .byte $90, $05 ; palette selector, target presentation flags
    .word $6B90, $0000, $8FCB ; frame, ordinary script, transferred script cursors
    .byte $90, $05 ; palette selector, target presentation flags
    .word $6B9E, $0000, $8FF8 ; frame, ordinary script, transferred script cursors
    .byte $90, $05 ; palette selector, target presentation flags
    .word $6BAE, $0000, $902A ; frame, ordinary script, transferred script cursors
    .byte $90, $05 ; palette selector, target presentation flags
    .word $6BBC, $0000, $9057 ; frame, ordinary script, transferred script cursors
    .byte $90, $05 ; palette selector, target presentation flags
    .word $6BD0, $0000, $9084 ; frame, ordinary script, transferred script cursors
