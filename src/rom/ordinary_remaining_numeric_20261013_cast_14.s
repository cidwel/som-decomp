; Numeric cast descriptors only; no referenced script/graphics payload.
.setcpu "65816"
.segment "RODATA"
.org $2FA0
ordinary_remaining_numeric_20261013_cast_14:
    .word $85FC ; hero actor script cursor
    .word $0E58, $0E58, $0E58 ; packed graphics resource parameters
    .byte $83, $00 ; palette selector, target presentation flags
    .word $6BE6, $0000, $90BB ; frame, ordinary script, transferred script cursors
    .byte $83, $00 ; palette selector, target presentation flags
    .word $6BE6, $0000, $90BB ; frame, ordinary script, transferred script cursors
    .byte $83, $00 ; palette selector, target presentation flags
    .word $6C0A, $0000, $90D1 ; frame, ordinary script, transferred script cursors
    .byte $83, $00 ; palette selector, target presentation flags
    .word $6C0A, $0000, $90D1 ; frame, ordinary script, transferred script cursors
    .byte $83, $00 ; palette selector, target presentation flags
    .word $6C36, $0000, $90EF ; frame, ordinary script, transferred script cursors
