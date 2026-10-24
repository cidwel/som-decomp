.setcpu "65816"
.segment "CODE"
.org $2D31
map_control_0f2d31:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
