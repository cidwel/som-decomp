.setcpu "65816"
.segment "CODE"
.org $531F
map_control_0d531f:
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
