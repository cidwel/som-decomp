.setcpu "65816"
.segment "CODE"
.org $70F2
map_control_0e70f2:
    .byte $E8 ; backreference distance high bits
    .byte $62 ; distance low bit/count
