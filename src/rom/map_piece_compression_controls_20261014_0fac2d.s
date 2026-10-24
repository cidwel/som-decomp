.setcpu "65816"
.segment "CODE"
.org $AC2D
map_control_0fac2d:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
