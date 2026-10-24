.setcpu "65816"
.segment "RODATA"
.org $2FDA
spell_14_combat_fields_numeric:
    .byte $3D, $4B, $02 ; power, accuracy, element
    .word $0080 ; status mask
    .byte $02 ; MP cost
