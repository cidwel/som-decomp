.setcpu "65816"
.segment "CODE"
.org $0549
map_control_0e0549:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
