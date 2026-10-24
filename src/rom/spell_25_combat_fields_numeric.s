.setcpu "65816"
.segment "RODATA"
.org $341A
spell_25_combat_fields_numeric:
    .byte $3D, $4B, $10 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $02 ; MP cost
