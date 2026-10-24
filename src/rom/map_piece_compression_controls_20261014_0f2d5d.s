.setcpu "65816"
.segment "CODE"
.org $2D5D
map_control_0f2d5d:
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
