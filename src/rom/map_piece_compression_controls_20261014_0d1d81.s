.setcpu "65816"
.segment "CODE"
.org $1D81
map_control_0d1d81:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
