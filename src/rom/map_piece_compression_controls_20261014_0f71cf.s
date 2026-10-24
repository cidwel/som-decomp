.setcpu "65816"
.segment "CODE"
.org $71CF
map_control_0f71cf:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
