.setcpu "65816"
.segment "CODE"
.org $0E8D
map_control_0e0e8d:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
