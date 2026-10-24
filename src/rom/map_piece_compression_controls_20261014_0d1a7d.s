.setcpu "65816"
.segment "CODE"
.org $1A7D
map_control_0d1a7d:
    .byte $E8 ; backreference distance high bits
    .byte $B6 ; distance low bit/count
