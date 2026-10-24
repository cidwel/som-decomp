.setcpu "65816"
.segment "RODATA"
.org $2E1A
spell_0d_combat_fields_numeric:
    .byte $3D, $4B, $08 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $04 ; MP cost
