.setcpu "65816"
.segment "CODE"
.org $CF72
map_control_0fcf72:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
