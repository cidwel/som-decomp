.setcpu "65816"
.segment "CODE"
.org $F3E0
map_control_0ef3e0:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
