.setcpu "65816"
.segment "CODE"
.org $A4C5
map_control_0fa4c5:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
