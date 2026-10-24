.setcpu "65816"
.segment "CODE"
.org $04B8
map_control_0e04b8:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
