.setcpu "65816"
.segment "CODE"
.org $9ABB
map_control_0d9abb:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
