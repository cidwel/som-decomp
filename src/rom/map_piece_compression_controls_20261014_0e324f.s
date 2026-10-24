.setcpu "65816"
.segment "CODE"
.org $324F
map_control_0e324f:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
