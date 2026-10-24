.setcpu "65816"
.segment "CODE"
.org $657D
map_control_0e657d:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
