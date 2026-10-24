.setcpu "65816"
.segment "CODE"
.org $DA7B
map_control_0dda7b:
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
