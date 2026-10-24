.setcpu "65816"
.segment "CODE"
.org $6C1D
map_control_0d6c1d:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
