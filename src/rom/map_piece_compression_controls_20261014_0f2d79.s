.setcpu "65816"
.segment "CODE"
.org $2D79
map_control_0f2d79:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
