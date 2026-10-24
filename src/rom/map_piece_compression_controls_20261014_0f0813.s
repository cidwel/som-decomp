.setcpu "65816"
.segment "CODE"
.org $0813
map_control_0f0813:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
