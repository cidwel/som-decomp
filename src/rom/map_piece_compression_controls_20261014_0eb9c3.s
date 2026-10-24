.setcpu "65816"
.segment "CODE"
.org $B9C3
map_control_0eb9c3:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
