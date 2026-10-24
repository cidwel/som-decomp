.setcpu "65816"
.segment "CODE"
.org $DAA9
map_control_0ddaa9:
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
