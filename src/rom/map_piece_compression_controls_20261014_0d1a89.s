.setcpu "65816"
.segment "CODE"
.org $1A89
map_control_0d1a89:
    .byte $E8 ; backreference distance high bits
    .byte $BD ; distance low bit/count
