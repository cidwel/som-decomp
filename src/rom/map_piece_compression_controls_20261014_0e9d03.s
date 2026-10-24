.setcpu "65816"
.segment "CODE"
.org $9D03
map_control_0e9d03:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
