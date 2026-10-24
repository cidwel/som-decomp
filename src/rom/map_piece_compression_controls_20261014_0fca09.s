.setcpu "65816"
.segment "CODE"
.org $CA09
map_control_0fca09:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
