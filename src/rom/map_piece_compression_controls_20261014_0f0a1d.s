.setcpu "65816"
.segment "CODE"
.org $0A1D
map_control_0f0a1d:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
