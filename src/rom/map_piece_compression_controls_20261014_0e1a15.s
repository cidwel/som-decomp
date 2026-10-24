.setcpu "65816"
.segment "CODE"
.org $1A15
map_control_0e1a15:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
