.setcpu "65816"
.segment "CODE"
.org $1B78
map_control_0d1b78:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
