.setcpu "65816"
.segment "CODE"
.org $F10D
map_control_0df10d:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
