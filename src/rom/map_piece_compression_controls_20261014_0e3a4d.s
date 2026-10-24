.setcpu "65816"
.segment "CODE"
.org $3A4D
map_control_0e3a4d:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
