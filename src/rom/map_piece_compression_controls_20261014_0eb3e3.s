.setcpu "65816"
.segment "CODE"
.org $B3E3
map_control_0eb3e3:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
