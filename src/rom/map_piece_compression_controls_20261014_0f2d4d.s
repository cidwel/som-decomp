.setcpu "65816"
.segment "CODE"
.org $2D4D
map_control_0f2d4d:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
