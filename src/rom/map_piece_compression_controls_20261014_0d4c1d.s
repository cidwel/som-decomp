.setcpu "65816"
.segment "CODE"
.org $4C1D
map_control_0d4c1d:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
