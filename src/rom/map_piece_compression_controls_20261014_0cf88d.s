.setcpu "65816"
.segment "CODE"
.org $F88D
map_control_0cf88d:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
