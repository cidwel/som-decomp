.setcpu "65816"
.segment "CODE"
.org $DA86
map_control_0dda86:
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
