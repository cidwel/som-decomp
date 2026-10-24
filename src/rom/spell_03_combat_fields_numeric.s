.setcpu "65816"
.segment "RODATA"
.org $2B9A
spell_03_combat_fields_numeric:
    .byte $3D, $4B, $01 ; power, accuracy, element
    .word $0040 ; status mask
    .byte $04 ; MP cost
