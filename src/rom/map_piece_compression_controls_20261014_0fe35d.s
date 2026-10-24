.setcpu "65816"
.segment "CODE"
.org $E35D
map_control_0fe35d:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
