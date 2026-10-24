.setcpu "65816"
.segment "CODE"
.org $71B1
map_control_0f71b1:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
