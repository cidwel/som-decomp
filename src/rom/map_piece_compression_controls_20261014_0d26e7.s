.setcpu "65816"
.segment "CODE"
.org $26E7
map_control_0d26e7:
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
