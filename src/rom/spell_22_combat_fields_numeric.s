.setcpu "65816"
.segment "RODATA"
.org $335A
spell_22_combat_fields_numeric:
    .byte $3D, $4B, $80 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $06 ; MP cost
