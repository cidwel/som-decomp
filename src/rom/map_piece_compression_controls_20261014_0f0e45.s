.setcpu "65816"
.segment "CODE"
.org $0E45
map_control_0f0e45:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
