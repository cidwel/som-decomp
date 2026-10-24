.setcpu "65816"
.segment "CODE"
.org $18F3
map_control_0d18f3:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
