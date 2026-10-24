.setcpu "65816"
.segment "CODE"
.org $2D0D
map_control_0f2d0d:
    .byte $E8 ; backreference distance high bits
    .byte $C1 ; distance low bit/count
