.setcpu "65816"
.segment "CODE"
.org $9C1D
map_control_0d9c1d:
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
