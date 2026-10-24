.setcpu "65816"
.segment "CODE"
.org $B1BF
map_control_0db1bf:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
