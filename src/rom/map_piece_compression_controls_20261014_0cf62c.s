.setcpu "65816"
.segment "CODE"
.org $F62C
map_control_0cf62c:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
