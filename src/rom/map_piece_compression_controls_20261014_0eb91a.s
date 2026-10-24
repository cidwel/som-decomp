.setcpu "65816"
.segment "CODE"
.org $B91A
map_control_0eb91a:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
