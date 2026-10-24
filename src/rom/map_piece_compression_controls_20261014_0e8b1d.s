.setcpu "65816"
.segment "CODE"
.org $8B1D
map_control_0e8b1d:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
