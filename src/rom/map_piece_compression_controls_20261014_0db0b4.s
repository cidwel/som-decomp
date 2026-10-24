.setcpu "65816"
.segment "CODE"
.org $B0B4
map_control_0db0b4:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
