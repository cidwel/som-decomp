.setcpu "65816"
.segment "CODE"
.org $E3FB
map_control_0de3fb:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
