.setcpu "65816"
.segment "CODE"
.org $2D35
map_control_0f2d35:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
