.setcpu "65816"
.segment "CODE"
.org $86FB
map_control_0c86fb:
    .byte $EC ; backreference distance high bits
    .byte $07 ; distance low bit/count
