.setcpu "65816"
.segment "CODE"
.org $9D8F
map_control_0d9d8f:
    .byte $E8 ; backreference distance high bits
    .byte $94 ; distance low bit/count
