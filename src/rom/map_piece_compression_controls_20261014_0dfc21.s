.setcpu "65816"
.segment "CODE"
.org $FC21
map_control_0dfc21:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
