.setcpu "65816"
.segment "CODE"
.org $F8EE
map_control_0cf8ee:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
