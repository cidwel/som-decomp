.setcpu "65816"
.segment "CODE"
.org $A6BC
map_control_0da6bc:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
