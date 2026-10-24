.setcpu "65816"
.segment "CODE"
.org $4654
map_control_0e4654:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
