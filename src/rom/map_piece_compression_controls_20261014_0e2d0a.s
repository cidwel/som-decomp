.setcpu "65816"
.segment "CODE"
.org $2D0A
map_control_0e2d0a:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
