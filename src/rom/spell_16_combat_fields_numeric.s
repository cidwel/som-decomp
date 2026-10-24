.setcpu "65816"
.segment "RODATA"
.org $305A
spell_16_combat_fields_numeric:
    .byte $3D, $4B, $02 ; power, accuracy, element
    .word $0100 ; status mask
    .byte $02 ; MP cost
