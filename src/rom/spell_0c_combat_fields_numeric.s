.setcpu "65816"
.segment "RODATA"
.org $2DDA
spell_0c_combat_fields_numeric:
    .byte $34, $4B, $08 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $02 ; MP cost
