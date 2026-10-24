.setcpu "65816"
.segment "CODE"
.org $B0CA
map_control_0fb0ca:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
