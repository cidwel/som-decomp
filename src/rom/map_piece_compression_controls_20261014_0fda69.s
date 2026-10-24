.setcpu "65816"
.segment "CODE"
.org $DA69
map_control_0fda69:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
