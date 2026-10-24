.setcpu "65816"
.segment "CODE"
.org $51AB
map_control_0c51ab:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
