.setcpu "65816"
.segment "CODE"
.org $2D2D
map_control_0f2d2d:
    .byte $E8 ; backreference distance high bits
    .byte $AC ; distance low bit/count
