.setcpu "65816"
.segment "CODE"
.org $37FA
map_control_0d37fa:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
