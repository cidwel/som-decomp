.setcpu "65816"
.segment "CODE"
.org $2D15
map_control_0f2d15:
    .byte $E8 ; backreference distance high bits
    .byte $C1 ; distance low bit/count
