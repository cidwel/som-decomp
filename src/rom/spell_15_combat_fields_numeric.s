.setcpu "65816"
.segment "RODATA"
.org $301A
spell_15_combat_fields_numeric:
    .byte $3D, $4B, $02 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $03 ; MP cost
