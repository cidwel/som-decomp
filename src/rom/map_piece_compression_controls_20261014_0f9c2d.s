.setcpu "65816"
.segment "CODE"
.org $9C2D
map_control_0f9c2d:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
