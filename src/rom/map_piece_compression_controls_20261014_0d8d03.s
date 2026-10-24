.setcpu "65816"
.segment "CODE"
.org $8D03
map_control_0d8d03:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
