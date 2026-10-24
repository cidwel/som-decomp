.setcpu "65816"
.segment "CODE"
.org $2D25
map_control_0f2d25:
    .byte $E8 ; backreference distance high bits
    .byte $C1 ; distance low bit/count
