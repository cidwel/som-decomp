.setcpu "65816"
.segment "CODE"
.org $2066
map_control_0d2066:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
