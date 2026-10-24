.setcpu "65816"
.segment "CODE"
.org $7D2D
map_control_0c7d2d:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
