.setcpu "65816"
.segment "CODE"
.org $F65F
map_control_0cf65f:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
