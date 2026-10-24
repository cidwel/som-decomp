.setcpu "65816"
.segment "CODE"
.org $3A78
map_control_0e3a78:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
