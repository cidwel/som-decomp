.setcpu "65816"
.segment "CODE"
.org $3E1D
map_control_0d3e1d:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
