.setcpu "65816"
.segment "CODE"
.org $F7A8
map_control_0cf7a8:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
