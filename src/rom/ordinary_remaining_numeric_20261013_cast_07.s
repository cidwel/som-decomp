; Numeric cast descriptors only; no referenced script/graphics payload.
.setcpu "65816"
.segment "RODATA"
.org $2C60
ordinary_remaining_numeric_20261013_cast_07:
    .word $85C6 ; hero actor script cursor
    .word $0C11, $0C11, $0C11 ; packed graphics resource parameters
    .byte $C5, $00 ; palette selector, target presentation flags
    .word $68C6, $0000, $8BA0 ; frame, ordinary script, transferred script cursors
    .byte $C5, $00 ; palette selector, target presentation flags
    .word $68C6, $0000, $8BA0 ; frame, ordinary script, transferred script cursors
    .byte $C5, $00 ; palette selector, target presentation flags
    .word $68C6, $0000, $8BCE ; frame, ordinary script, transferred script cursors
    .byte $C5, $00 ; palette selector, target presentation flags
    .word $68C6, $0000, $8BCE ; frame, ordinary script, transferred script cursors
    .byte $C5, $00 ; palette selector, target presentation flags
    .word $68C6, $0000, $8C0E ; frame, ordinary script, transferred script cursors
