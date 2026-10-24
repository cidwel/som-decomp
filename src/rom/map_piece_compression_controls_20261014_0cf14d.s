.setcpu "65816"
.segment "CODE"
.org $F14D
map_control_0cf14d:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
