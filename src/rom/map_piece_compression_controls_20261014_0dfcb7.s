.setcpu "65816"
.segment "CODE"
.org $FCB7
map_control_0dfcb7:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
