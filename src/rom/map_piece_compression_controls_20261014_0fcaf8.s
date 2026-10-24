.setcpu "65816"
.segment "CODE"
.org $CAF8
map_control_0fcaf8:
    .byte $EA ; backreference distance high bits
    .byte $06 ; distance low bit/count
