.setcpu "65816"
.segment "CODE"
.org $A4B4
map_control_0fa4b4:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
