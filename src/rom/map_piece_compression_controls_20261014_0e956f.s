.setcpu "65816"
.segment "CODE"
.org $956F
map_control_0e956f:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
