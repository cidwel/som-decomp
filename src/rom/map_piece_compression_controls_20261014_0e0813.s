.setcpu "65816"
.segment "CODE"
.org $0813
map_control_0e0813:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
