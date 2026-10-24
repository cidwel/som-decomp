.setcpu "65816"
.segment "RODATA"
.org $2B1A
spell_01_combat_fields_numeric:
    .byte $2B, $4B, $01 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $02 ; MP cost
