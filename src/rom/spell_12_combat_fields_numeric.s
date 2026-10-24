.setcpu "65816"
.segment "RODATA"
.org $2F5A
spell_12_combat_fields_numeric:
    .byte $2B, $4B, $02 ; power, accuracy, element
    .word $0000 ; status mask
    .byte $02 ; MP cost
