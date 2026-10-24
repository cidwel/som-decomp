.setcpu "65816"
.segment "CODE"
.org $4C6A
map_control_0d4c6a:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
