.setcpu "65816"
.segment "CODE"
.org $2D21
map_control_0f2d21:
    .byte $E8 ; backreference distance high bits
    .byte $C1 ; distance low bit/count
