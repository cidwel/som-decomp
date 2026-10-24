.setcpu "65816"
.segment "RODATA"
.org $349A
spell_27_combat_fields_numeric:
    .byte $3D, $4B, $20 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $05 ; MP cost
