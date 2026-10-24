.setcpu "65816"
.segment "RODATA"
.org $2E5A
spell_0e_combat_fields_numeric:
    .byte $2B, $4B, $08 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $03 ; MP cost
