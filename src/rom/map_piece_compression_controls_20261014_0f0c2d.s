.setcpu "65816"
.segment "CODE"
.org $0C2D
map_control_0f0c2d:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
