.setcpu "65816"
.segment "CODE"
.org $1C96
map_control_0e1c96:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
