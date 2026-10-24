.setcpu "65816"
.segment "RODATA"
.org $331A
spell_21_combat_fields_numeric:
    .byte $3D, $4B, $80 ; power, accuracy, element
    .word $8000 ; status mask
    .byte $0A ; MP cost
