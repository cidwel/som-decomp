.setcpu "65816"
.segment "CODE"
.org $0E6D
map_control_0f0e6d:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
