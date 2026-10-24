.setcpu "65816"
.segment "CODE"
.org $92AB
map_control_0e92ab:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
