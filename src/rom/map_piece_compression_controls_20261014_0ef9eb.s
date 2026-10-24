.setcpu "65816"
.segment "CODE"
.org $F9EB
map_control_0ef9eb:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
