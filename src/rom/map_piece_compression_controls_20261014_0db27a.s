.setcpu "65816"
.segment "CODE"
.org $B27A
map_control_0db27a:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
