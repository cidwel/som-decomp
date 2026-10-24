.setcpu "65816"
.segment "CODE"
.org $0F55
map_control_0e0f55:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
