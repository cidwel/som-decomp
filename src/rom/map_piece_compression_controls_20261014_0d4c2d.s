.setcpu "65816"
.segment "CODE"
.org $4C2D
map_control_0d4c2d:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
