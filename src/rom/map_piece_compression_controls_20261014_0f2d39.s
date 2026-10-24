.setcpu "65816"
.segment "CODE"
.org $2D39
map_control_0f2d39:
    .byte $E8 ; backreference distance high bits
    .byte $AB ; distance low bit/count
