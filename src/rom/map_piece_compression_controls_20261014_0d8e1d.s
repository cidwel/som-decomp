.setcpu "65816"
.segment "CODE"
.org $8E1D
map_control_0d8e1d:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
