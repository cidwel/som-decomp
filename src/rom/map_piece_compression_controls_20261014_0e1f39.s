.setcpu "65816"
.segment "CODE"
.org $1F39
map_control_0e1f39:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
