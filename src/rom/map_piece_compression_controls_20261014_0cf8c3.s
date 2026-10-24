.setcpu "65816"
.segment "CODE"
.org $F8C3
map_control_0cf8c3:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
