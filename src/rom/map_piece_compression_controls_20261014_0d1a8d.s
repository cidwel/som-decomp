.setcpu "65816"
.segment "CODE"
.org $1A8D
map_control_0d1a8d:
    .byte $E8 ; backreference distance high bits
    .byte $BD ; distance low bit/count
