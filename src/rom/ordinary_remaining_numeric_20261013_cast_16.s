; Numeric cast descriptors only; no referenced script/graphics payload.
.setcpu "65816"
.segment "RODATA"
.org $3020
ordinary_remaining_numeric_20261013_cast_16:
    .word $85FC ; hero actor script cursor
    .word $0429, $0429, $0429 ; packed graphics resource parameters
    .byte $94, $00 ; palette selector, target presentation flags
    .word $6C66, $0000, $911D ; frame, ordinary script, transferred script cursors
    .byte $94, $00 ; palette selector, target presentation flags
    .word $6C66, $0000, $911D ; frame, ordinary script, transferred script cursors
    .byte $95, $00 ; palette selector, target presentation flags
    .word $6C66, $0000, $912B ; frame, ordinary script, transferred script cursors
    .byte $95, $00 ; palette selector, target presentation flags
    .word $6C66, $0000, $912B ; frame, ordinary script, transferred script cursors
    .byte $93, $00 ; palette selector, target presentation flags
    .word $6C78, $0000, $9139 ; frame, ordinary script, transferred script cursors
