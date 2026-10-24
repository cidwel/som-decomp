.setcpu "65816"
.segment "CODE"
.org $7E6F
map_control_0c7e6f:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
