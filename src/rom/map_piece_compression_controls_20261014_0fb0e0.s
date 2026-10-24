.setcpu "65816"
.segment "CODE"
.org $B0E0
map_control_0fb0e0:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
