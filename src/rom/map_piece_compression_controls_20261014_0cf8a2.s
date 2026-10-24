.setcpu "65816"
.segment "CODE"
.org $F8A2
map_control_0cf8a2:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
