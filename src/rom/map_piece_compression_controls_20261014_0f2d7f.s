.setcpu "65816"
.segment "CODE"
.org $2D7F
map_control_0f2d7f:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
