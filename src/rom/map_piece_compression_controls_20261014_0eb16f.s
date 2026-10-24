.setcpu "65816"
.segment "CODE"
.org $B16F
map_control_0eb16f:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
