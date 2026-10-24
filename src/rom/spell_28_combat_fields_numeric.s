.setcpu "65816"
.segment "RODATA"
.org $34DA
spell_28_combat_fields_numeric:
    .byte $3D, $4B, $20 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $08 ; MP cost
