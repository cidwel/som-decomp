.setcpu "65816"
.segment "CODE"
.org $1403
map_control_0e1403:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
