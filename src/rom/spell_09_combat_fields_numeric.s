.setcpu "65816"
.segment "RODATA"
.org $2D1A
spell_09_combat_fields_numeric:
    .byte $3D, $4B, $04 ; power, accuracy, element
    .word $0020 ; status mask
    .byte $02 ; MP cost
