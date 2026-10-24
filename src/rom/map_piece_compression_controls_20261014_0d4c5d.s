.setcpu "65816"
.segment "CODE"
.org $4C5D
map_control_0d4c5d:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
