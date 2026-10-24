.setcpu "65816"
.segment "CODE"
.org $2D1F
map_control_0e2d1f:
    .byte $E9 ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
