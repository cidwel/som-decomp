.setcpu "65816"
.segment "CODE"
.org $1997
map_control_0e1997:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
