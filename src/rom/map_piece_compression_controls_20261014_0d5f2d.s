.setcpu "65816"
.segment "CODE"
.org $5F2D
map_control_0d5f2d:
    .byte $EF ; backreference distance high bits
    .byte $0B ; distance low bit/count
