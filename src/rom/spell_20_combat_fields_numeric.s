.setcpu "65816"
.segment "RODATA"
.org $32DA
spell_20_combat_fields_numeric:
    .byte $FA, $4B, $80 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $01 ; MP cost
