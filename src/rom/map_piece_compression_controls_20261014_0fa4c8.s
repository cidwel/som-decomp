.setcpu "65816"
.segment "CODE"
.org $A4C8
map_control_0fa4c8:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
