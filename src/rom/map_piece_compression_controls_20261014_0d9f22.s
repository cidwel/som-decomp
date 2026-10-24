.setcpu "65816"
.segment "CODE"
.org $9F22
map_control_0d9f22:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
