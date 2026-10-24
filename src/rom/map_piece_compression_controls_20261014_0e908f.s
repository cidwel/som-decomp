.setcpu "65816"
.segment "CODE"
.org $908F
map_control_0e908f:
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
