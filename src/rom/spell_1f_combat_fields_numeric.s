.setcpu "65816"
.segment "RODATA"
.org $329A
spell_1f_combat_fields_numeric:
    .byte $64, $4B, $80 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $04 ; MP cost
