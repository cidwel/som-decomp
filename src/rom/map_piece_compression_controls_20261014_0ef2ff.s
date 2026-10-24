.setcpu "65816"
.segment "CODE"
.org $F2FF
map_control_0ef2ff:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
