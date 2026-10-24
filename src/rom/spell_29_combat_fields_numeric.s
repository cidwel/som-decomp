.setcpu "65816"
.segment "RODATA"
.org $351A
spell_29_combat_fields_numeric:
    .byte $3D, $4B, $20 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $04 ; MP cost
