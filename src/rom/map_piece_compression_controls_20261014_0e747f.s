.setcpu "65816"
.segment "CODE"
.org $747F
map_control_0e747f:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
