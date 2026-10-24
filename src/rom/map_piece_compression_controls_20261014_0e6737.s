.setcpu "65816"
.segment "CODE"
.org $6737
map_control_0e6737:
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
