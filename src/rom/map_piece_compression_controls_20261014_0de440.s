.setcpu "65816"
.segment "CODE"
.org $E440
map_control_0de440:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
