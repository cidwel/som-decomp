.setcpu "65816"
.segment "CODE"
.org $2D55
map_control_0f2d55:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
