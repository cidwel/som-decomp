.setcpu "65816"
.segment "CODE"
.org $0EC5
map_control_0e0ec5:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
