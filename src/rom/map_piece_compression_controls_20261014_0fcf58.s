.setcpu "65816"
.segment "CODE"
.org $CF58
map_control_0fcf58:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
