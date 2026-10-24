.setcpu "65816"
.segment "CODE"
.org $B9A0
map_control_0eb9a0:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
