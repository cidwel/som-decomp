.setcpu "65816"
.segment "RODATA"
.org $309A
spell_17_combat_fields_numeric:
    .byte $3D, $4B, $02 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $01 ; MP cost
