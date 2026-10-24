.setcpu "65816"
.segment "CODE"
.org $4C3C
map_control_0d4c3c:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
