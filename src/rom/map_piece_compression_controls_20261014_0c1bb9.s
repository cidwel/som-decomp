.setcpu "65816"
.segment "CODE"
.org $1BB9
map_control_0c1bb9:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
