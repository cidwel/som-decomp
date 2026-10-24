.setcpu "65816"
.segment "CODE"
.org $8C2D
map_control_0d8c2d:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
