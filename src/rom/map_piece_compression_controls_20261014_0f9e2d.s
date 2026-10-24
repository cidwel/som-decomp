.setcpu "65816"
.segment "CODE"
.org $9E2D
map_control_0f9e2d:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
