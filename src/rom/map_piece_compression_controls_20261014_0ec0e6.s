.setcpu "65816"
.segment "CODE"
.org $C0E6
map_control_0ec0e6:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
