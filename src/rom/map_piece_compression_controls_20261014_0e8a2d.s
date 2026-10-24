.setcpu "65816"
.segment "CODE"
.org $8A2D
map_control_0e8a2d:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
