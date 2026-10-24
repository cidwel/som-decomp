.setcpu "65816"
.segment "CODE"
.org $86E7
map_control_0c86e7:
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
