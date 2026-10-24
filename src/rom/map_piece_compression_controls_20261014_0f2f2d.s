.setcpu "65816"
.segment "CODE"
.org $2F2D
map_control_0f2f2d:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
