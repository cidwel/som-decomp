.setcpu "65816"
.segment "CODE"
.org $9C8D
map_control_0e9c8d:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
