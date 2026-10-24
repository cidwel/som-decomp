.setcpu "65816"
.segment "CODE"
.org $B17F
map_control_0db17f:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
