.setcpu "65816"
.segment "CODE"
.org $DA83
map_control_0dda83:
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
