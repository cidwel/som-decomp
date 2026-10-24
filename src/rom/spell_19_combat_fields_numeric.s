.setcpu "65816"
.segment "RODATA"
.org $311A
spell_19_combat_fields_numeric:
    .byte $2B, $4B, $40 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $01 ; MP cost
