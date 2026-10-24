.setcpu "65816"
.segment "CODE"
.org $91FB
map_control_0f91fb:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
