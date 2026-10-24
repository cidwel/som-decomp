; Numeric cast descriptors only; no referenced script/graphics payload.
.setcpu "65816"
.segment "RODATA"
.org $2CA0
ordinary_remaining_numeric_20261013_cast_08:
    .word $85C6 ; hero actor script cursor
    .word $0FC0, $0FC0, $0FC0 ; packed graphics resource parameters
    .byte $99, $00 ; palette selector, target presentation flags
    .word $68F8, $0000, $8C86 ; frame, ordinary script, transferred script cursors
    .byte $99, $00 ; palette selector, target presentation flags
    .word $68F8, $0000, $8C86 ; frame, ordinary script, transferred script cursors
    .byte $99, $00 ; palette selector, target presentation flags
    .word $6928, $0000, $8C86 ; frame, ordinary script, transferred script cursors
    .byte $99, $00 ; palette selector, target presentation flags
    .word $6928, $0000, $8C86 ; frame, ordinary script, transferred script cursors
    .byte $99, $00 ; palette selector, target presentation flags
    .word $6958, $0000, $8CA6 ; frame, ordinary script, transferred script cursors
