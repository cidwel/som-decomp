.setcpu "65816"
.segment "CODE"
.org $20E1
map_control_0e20e1:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
