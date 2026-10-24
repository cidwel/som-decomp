.setcpu "65816"
.segment "CODE"
.org $2D1D
map_control_0f2d1d:
    .byte $E8 ; backreference distance high bits
    .byte $C1 ; distance low bit/count
