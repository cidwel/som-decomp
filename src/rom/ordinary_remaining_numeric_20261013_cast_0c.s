; Numeric cast descriptors only; no referenced script/graphics payload.
.setcpu "65816"
.segment "RODATA"
.org $2DA0
ordinary_remaining_numeric_20261013_cast_0c:
    .word $85E0 ; hero actor script cursor
    .word $04C3, $04C3, $04C3 ; packed graphics resource parameters
    .byte $89, $02 ; palette selector, target presentation flags
    .word $6A20, $9702, $8D39 ; frame, ordinary script, transferred script cursors
    .byte $89, $02 ; palette selector, target presentation flags
    .word $6A22, $9702, $8D52 ; frame, ordinary script, transferred script cursors
    .byte $89, $02 ; palette selector, target presentation flags
    .word $6A24, $9702, $8D6F ; frame, ordinary script, transferred script cursors
    .byte $89, $02 ; palette selector, target presentation flags
    .word $6A26, $9702, $8D90 ; frame, ordinary script, transferred script cursors
    .byte $89, $0C ; palette selector, target presentation flags
    .word $6A26, $0000, $8D90 ; frame, ordinary script, transferred script cursors
