.setcpu "65816"
.segment "CODE"
.org $46F0
map_control_0c46f0:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
