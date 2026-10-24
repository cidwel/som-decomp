.setcpu "65816"
.segment "RODATA"
.org $2F1A
spell_11_combat_fields_numeric:
    .byte $20, $4B, $08 ; power, accuracy, element
    .word $4000 ; status mask
    .byte $04 ; MP cost
