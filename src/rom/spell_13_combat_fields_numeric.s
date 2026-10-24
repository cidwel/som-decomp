.setcpu "65816"
.segment "RODATA"
.org $2F9A
spell_13_combat_fields_numeric:
    .byte $3D, $4B, $02 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $04 ; MP cost
