.setcpu "65816"
.segment "CODE"
.org $2A9D
map_control_0e2a9d:
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
