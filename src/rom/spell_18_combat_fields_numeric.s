.setcpu "65816"
.segment "RODATA"
.org $30DA
spell_18_combat_fields_numeric:
    .byte $3D, $4B, $40 ; power, accuracy, element
    .word $0800 ; status mask
    .byte $05 ; MP cost
