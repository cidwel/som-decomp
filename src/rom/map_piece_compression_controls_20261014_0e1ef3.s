.setcpu "65816"
.segment "CODE"
.org $1EF3
map_control_0e1ef3:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
