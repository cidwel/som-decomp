.setcpu "65816"
.segment "CODE"
.org $27A3
map_control_0d27a3:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
