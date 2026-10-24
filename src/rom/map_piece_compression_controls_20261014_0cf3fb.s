.setcpu "65816"
.segment "CODE"
.org $F3FB
map_control_0cf3fb:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
