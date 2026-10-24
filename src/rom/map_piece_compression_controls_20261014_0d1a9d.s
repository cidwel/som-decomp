.setcpu "65816"
.segment "CODE"
.org $1A9D
map_control_0d1a9d:
    .byte $E8 ; backreference distance high bits
    .byte $BD ; distance low bit/count
