.setcpu "65816"
.segment "CODE"
.org $3E2D
map_control_0d3e2d:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
