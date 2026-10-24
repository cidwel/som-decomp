.setcpu "65816"
.segment "CODE"
.org $3533
map_control_0e3533:
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
