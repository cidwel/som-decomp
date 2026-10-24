.setcpu "65816"
.segment "CODE"
.org $2D96
map_control_0f2d96:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
