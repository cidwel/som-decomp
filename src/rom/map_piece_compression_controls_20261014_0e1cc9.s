.setcpu "65816"
.segment "CODE"
.org $1CC9
map_control_0e1cc9:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
