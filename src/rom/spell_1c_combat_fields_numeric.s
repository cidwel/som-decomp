.setcpu "65816"
.segment "RODATA"
.org $31DA
spell_1c_combat_fields_numeric:
    .byte $3D, $4B, $40 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $02 ; MP cost
