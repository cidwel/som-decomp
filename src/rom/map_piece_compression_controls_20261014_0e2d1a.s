.setcpu "65816"
.segment "CODE"
.org $2D1A
map_control_0e2d1a:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
