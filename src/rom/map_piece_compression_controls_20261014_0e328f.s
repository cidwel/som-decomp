.setcpu "65816"
.segment "CODE"
.org $328F
map_control_0e328f:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
