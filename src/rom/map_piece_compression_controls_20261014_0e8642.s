.setcpu "65816"
.segment "CODE"
.org $8642
map_control_0e8642:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
