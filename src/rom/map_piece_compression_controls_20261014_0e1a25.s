.setcpu "65816"
.segment "CODE"
.org $1A25
map_control_0e1a25:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
