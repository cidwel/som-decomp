; Numeric cast descriptors only; no referenced script/graphics payload.
.setcpu "65816"
.segment "RODATA"
.org $2E20
ordinary_remaining_numeric_20261013_cast_0e:
    .word $85E0 ; hero actor script cursor
    .word $050E, $050E, $050E ; packed graphics resource parameters
    .byte $8B, $00 ; palette selector, target presentation flags
    .word $6A74, $970D, $8E09 ; frame, ordinary script, transferred script cursors
    .byte $8B, $00 ; palette selector, target presentation flags
    .word $6A74, $970D, $8E21 ; frame, ordinary script, transferred script cursors
    .byte $8B, $00 ; palette selector, target presentation flags
    .word $6A8C, $970D, $8E47 ; frame, ordinary script, transferred script cursors
    .byte $8B, $00 ; palette selector, target presentation flags
    .word $6A8C, $970D, $8E7D ; frame, ordinary script, transferred script cursors
    .byte $8C, $00 ; palette selector, target presentation flags
    .word $6AA6, $970D, $8EBC ; frame, ordinary script, transferred script cursors
