.setcpu "65816"
.segment "CODE"
.org $1ED3
map_control_0e1ed3:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
