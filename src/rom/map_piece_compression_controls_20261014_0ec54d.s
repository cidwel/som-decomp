.setcpu "65816"
.segment "CODE"
.org $C54D
map_control_0ec54d:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
