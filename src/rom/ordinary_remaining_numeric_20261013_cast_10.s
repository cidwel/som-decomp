; Numeric cast descriptors only; no referenced script/graphics payload.
.setcpu "65816"
.segment "RODATA"
.org $2EA0
ordinary_remaining_numeric_20261013_cast_10:
    .word $85E0 ; hero actor script cursor
    .word $0553, $0553, $0553 ; packed graphics resource parameters
    .byte $89, $00 ; palette selector, target presentation flags
    .word $6ABE, $0000, $8F2D ; frame, ordinary script, transferred script cursors
    .byte $89, $00 ; palette selector, target presentation flags
    .word $6ABE, $0000, $8F2D ; frame, ordinary script, transferred script cursors
    .byte $89, $00 ; palette selector, target presentation flags
    .word $6AD4, $0000, $8F2D ; frame, ordinary script, transferred script cursors
    .byte $89, $00 ; palette selector, target presentation flags
    .word $6AD4, $0000, $8F2D ; frame, ordinary script, transferred script cursors
    .byte $89, $0E ; palette selector, target presentation flags
    .word $6AD4, $0000, $8F55 ; frame, ordinary script, transferred script cursors
