.setcpu "65816"
.segment "CODE"
.org $998D
map_control_0e998d:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
