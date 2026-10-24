.setcpu "65816"
.segment "CODE"
.org $27D8
map_control_0f27d8:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
