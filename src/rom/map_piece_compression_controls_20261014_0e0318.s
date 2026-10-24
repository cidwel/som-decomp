.setcpu "65816"
.segment "CODE"
.org $0318
map_control_0e0318:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
