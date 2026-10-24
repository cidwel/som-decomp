.setcpu "65816"
.segment "CODE"
.org $4136
map_control_0e4136:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
