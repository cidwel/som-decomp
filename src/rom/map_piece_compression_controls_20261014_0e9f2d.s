.setcpu "65816"
.segment "CODE"
.org $9F2D
map_control_0e9f2d:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
