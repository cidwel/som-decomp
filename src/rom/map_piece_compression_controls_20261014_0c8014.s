.setcpu "65816"
.segment "CODE"
.org $8014
map_control_0c8014:
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
