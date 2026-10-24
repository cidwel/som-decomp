.setcpu "65816"
.segment "CODE"
.org $1540
map_control_0e1540:
    .byte $E8 ; backreference distance high bits
    .byte $72 ; distance low bit/count
