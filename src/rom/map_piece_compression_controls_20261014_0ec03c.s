.setcpu "65816"
.segment "CODE"
.org $C03C
map_control_0ec03c:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
