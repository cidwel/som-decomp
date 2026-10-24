.setcpu "65816"
.segment "CODE"
.org $30F0
map_control_0e30f0:
    .byte $E8 ; backreference distance high bits
    .byte $9B ; distance low bit/count
