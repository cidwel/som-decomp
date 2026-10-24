.setcpu "65816"
.segment "CODE"
.org $1F55
map_control_0e1f55:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
