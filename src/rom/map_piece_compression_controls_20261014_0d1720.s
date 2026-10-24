.setcpu "65816"
.segment "CODE"
.org $1720
map_control_0d1720:
    .byte $EC ; backreference distance high bits
    .byte $86 ; distance low bit/count
