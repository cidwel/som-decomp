.setcpu "65816"
.segment "CODE"
.org $5326
map_control_0e5326:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
