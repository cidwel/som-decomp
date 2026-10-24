.setcpu "65816"
.segment "RODATA"
.org $2D9A
spell_0b_combat_fields_numeric:
    .byte $3D, $4B, $04 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $02 ; MP cost
