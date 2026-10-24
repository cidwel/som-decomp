.setcpu "65816"
.segment "CODE"
.org $B3E7
map_control_0eb3e7:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
