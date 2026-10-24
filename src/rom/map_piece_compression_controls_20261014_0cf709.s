.setcpu "65816"
.segment "CODE"
.org $F709
map_control_0cf709:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
