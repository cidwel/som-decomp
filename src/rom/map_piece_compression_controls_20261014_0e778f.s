.setcpu "65816"
.segment "CODE"
.org $778F
map_control_0e778f:
    .byte $EA ; backreference distance high bits
    .byte $08 ; distance low bit/count
