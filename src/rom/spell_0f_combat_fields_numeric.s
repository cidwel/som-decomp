.setcpu "65816"
.segment "RODATA"
.org $2E9A
spell_0f_combat_fields_numeric:
    .byte $3D, $4B, $08 ; power, accuracy, element
    .word $4000 ; status mask
    .byte $02 ; MP cost
