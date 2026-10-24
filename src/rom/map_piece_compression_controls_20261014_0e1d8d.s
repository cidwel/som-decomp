.setcpu "65816"
.segment "CODE"
.org $1D8D
map_control_0e1d8d:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
