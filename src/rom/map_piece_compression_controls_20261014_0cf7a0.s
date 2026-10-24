.setcpu "65816"
.segment "CODE"
.org $F7A0
map_control_0cf7a0:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
