.setcpu "65816"
.segment "CODE"
.org $B3FB
map_control_0eb3fb:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
