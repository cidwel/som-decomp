.setcpu "65816"
.segment "CODE"
.org $2D42
map_control_0f2d42:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
