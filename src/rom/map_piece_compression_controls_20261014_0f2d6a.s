.setcpu "65816"
.segment "CODE"
.org $2D6A
map_control_0f2d6a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
