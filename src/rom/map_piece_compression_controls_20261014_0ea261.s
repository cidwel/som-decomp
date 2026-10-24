.setcpu "65816"
.segment "CODE"
.org $A261
map_control_0ea261:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
