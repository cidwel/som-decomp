.setcpu "65816"
.segment "CODE"
.org $1092
map_control_0c1092:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
