.setcpu "65816"
.segment "CODE"
.org $AC1D
map_control_0dac1d:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
