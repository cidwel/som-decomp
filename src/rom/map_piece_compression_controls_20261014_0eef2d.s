.setcpu "65816"
.segment "CODE"
.org $EF2D
map_control_0eef2d:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
