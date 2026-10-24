.setcpu "65816"
.segment "CODE"
.org $E4FB
map_control_0de4fb:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
