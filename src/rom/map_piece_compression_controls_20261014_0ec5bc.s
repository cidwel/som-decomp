.setcpu "65816"
.segment "CODE"
.org $C5BC
map_control_0ec5bc:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
