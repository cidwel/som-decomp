.setcpu "65816"
.segment "CODE"
.org $E81F
map_control_0fe81f:
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
