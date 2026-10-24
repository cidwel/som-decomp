.setcpu "65816"
.segment "CODE"
.org $2D72
map_control_0f2d72:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
