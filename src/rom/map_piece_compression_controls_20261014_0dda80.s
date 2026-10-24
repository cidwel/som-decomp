.setcpu "65816"
.segment "CODE"
.org $DA80
map_control_0dda80:
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
