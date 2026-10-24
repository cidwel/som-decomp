.setcpu "65816"
.segment "CODE"
.org $777F
map_control_0e777f:
    .byte $EC ; backreference distance high bits
    .byte $07 ; distance low bit/count
