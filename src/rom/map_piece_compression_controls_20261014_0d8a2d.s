.setcpu "65816"
.segment "CODE"
.org $8A2D
map_control_0d8a2d:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
