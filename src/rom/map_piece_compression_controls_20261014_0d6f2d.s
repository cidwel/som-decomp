.setcpu "65816"
.segment "CODE"
.org $6F2D
map_control_0d6f2d:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
