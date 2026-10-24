.setcpu "65816"
.segment "CODE"
.org $0842
map_control_0d0842:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
