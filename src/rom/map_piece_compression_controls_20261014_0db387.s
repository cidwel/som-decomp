.setcpu "65816"
.segment "CODE"
.org $B387
map_control_0db387:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
