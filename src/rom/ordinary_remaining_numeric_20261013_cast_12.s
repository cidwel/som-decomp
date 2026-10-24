; Numeric cast descriptors only; no referenced script/graphics payload.
.setcpu "65816"
.segment "RODATA"
.org $2F20
ordinary_remaining_numeric_20261013_cast_12:
    .word $85FC ; hero actor script cursor
    .word $06BC, $0EBC, $0EBC ; packed graphics resource parameters
    .byte $90, $01 ; palette selector, target presentation flags
    .word $6B70, $9716, $8FA4 ; frame, ordinary script, transferred script cursors
    .byte $90, $01 ; palette selector, target presentation flags
    .word $6B74, $9722, $8FA4 ; frame, ordinary script, transferred script cursors
    .byte $90, $01 ; palette selector, target presentation flags
    .word $6B74, $9722, $8FA4 ; frame, ordinary script, transferred script cursors
    .byte $90, $01 ; palette selector, target presentation flags
    .word $6B76, $9722, $8FA4 ; frame, ordinary script, transferred script cursors
    .byte $90, $00 ; palette selector, target presentation flags
    .word $6B78, $9730, $8FB4 ; frame, ordinary script, transferred script cursors
