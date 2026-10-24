.setcpu "65816"
.segment "CODE"
.org $9E3F
map_control_0d9e3f:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
