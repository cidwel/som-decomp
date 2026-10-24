.setcpu "65816"
.segment "CODE"
.org $0CB3
map_control_0d0cb3:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
