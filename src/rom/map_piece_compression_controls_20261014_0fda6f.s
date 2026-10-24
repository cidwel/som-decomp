.setcpu "65816"
.segment "CODE"
.org $DA6F
map_control_0fda6f:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
