.setcpu "65816"
.segment "CODE"
.org $CF3F
map_control_0fcf3f:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
