.setcpu "65816"
.segment "CODE"
.org $F2FB
map_control_0cf2fb:
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
