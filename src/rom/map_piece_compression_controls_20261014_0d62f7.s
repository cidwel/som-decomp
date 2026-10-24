.setcpu "65816"
.segment "CODE"
.org $62F7
map_control_0d62f7:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
