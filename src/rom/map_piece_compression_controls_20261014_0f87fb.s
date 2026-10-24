.setcpu "65816"
.segment "CODE"
.org $87FB
map_control_0f87fb:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
