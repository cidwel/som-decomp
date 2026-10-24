.setcpu "65816"
.segment "CODE"
.org $478B
map_control_0d478b:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
