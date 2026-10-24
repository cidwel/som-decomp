.setcpu "65816"
.segment "CODE"
.org $1A56
map_control_0d1a56:
    .byte $E8 ; backreference distance high bits
    .byte $94 ; distance low bit/count
