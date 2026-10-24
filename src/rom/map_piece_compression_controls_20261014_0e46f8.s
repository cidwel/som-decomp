.setcpu "65816"
.segment "CODE"
.org $46F8
map_control_0e46f8:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
