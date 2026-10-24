.setcpu "65816"
.segment "CODE"
.org $1FC8
map_control_0e1fc8:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
