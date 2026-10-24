.setcpu "65816"
.segment "RODATA"
.org $33DA
spell_24_combat_fields_numeric:
    .byte $3D, $4B, $10 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $08 ; MP cost
