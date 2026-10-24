.setcpu "65816"
.segment "RODATA"
.org $325A
spell_1e_combat_fields_numeric:
    .byte $3D, $4B, $80 ; power, accuracy, element
    .word $0010 ; status mask
    .byte $02 ; MP cost
