.setcpu "65816"
.segment "CODE"
.org $1D9C
map_control_0d1d9c:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
