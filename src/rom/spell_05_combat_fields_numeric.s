.setcpu "65816"
.segment "RODATA"
.org $2C1A
spell_05_combat_fields_numeric:
    .byte $3D, $4B, $01 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $02 ; MP cost
