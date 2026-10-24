.setcpu "65816"
.segment "CODE"
.org $A468
map_control_0ea468:
    .byte $EA ; backreference distance high bits
    .byte $0A ; distance low bit/count
