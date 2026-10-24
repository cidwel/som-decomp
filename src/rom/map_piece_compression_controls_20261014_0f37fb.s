.setcpu "65816"
.segment "CODE"
.org $37FB
map_control_0f37fb:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
