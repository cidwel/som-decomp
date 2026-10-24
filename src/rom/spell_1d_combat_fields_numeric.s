.setcpu "65816"
.segment "RODATA"
.org $321A
spell_1d_combat_fields_numeric:
    .byte $3D, $4B, $40 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $02 ; MP cost
