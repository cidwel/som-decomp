.setcpu "65816"
.segment "CODE"
.org $CDA3
map_control_0fcda3:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
