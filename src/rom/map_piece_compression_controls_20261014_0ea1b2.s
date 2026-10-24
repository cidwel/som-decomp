.setcpu "65816"
.segment "CODE"
.org $A1B2
map_control_0ea1b2:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
