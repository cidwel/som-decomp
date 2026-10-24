.setcpu "65816"
.segment "RODATA"
.org $2B5A
spell_02_combat_fields_numeric:
    .byte $3D, $4B, $01 ; power, accuracy, element
    .word $0004 ; status mask
    .byte $01 ; MP cost
