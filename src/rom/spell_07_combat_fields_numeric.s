.setcpu "65816"
.segment "RODATA"
.org $2C9A
spell_07_combat_fields_numeric:
    .byte $2B, $4B, $04 ; power, accuracy, element
    .word $2000 ; status mask
    .byte $03 ; MP cost
