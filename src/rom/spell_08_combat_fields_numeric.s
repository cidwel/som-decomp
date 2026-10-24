.setcpu "65816"
.segment "RODATA"
.org $2CDA
spell_08_combat_fields_numeric:
    .byte $2B, $4B, $04 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $02 ; MP cost
