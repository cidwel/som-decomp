.setcpu "65816"
.segment "CODE"
.org $978D
map_control_0e978d:
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
