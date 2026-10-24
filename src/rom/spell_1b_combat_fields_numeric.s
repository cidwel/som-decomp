.setcpu "65816"
.segment "RODATA"
.org $319A
spell_1b_combat_fields_numeric:
    .byte $3D, $4B, $40 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $03 ; MP cost
