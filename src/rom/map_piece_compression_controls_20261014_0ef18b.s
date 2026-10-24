.setcpu "65816"
.segment "CODE"
.org $F18B
map_control_0ef18b:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
