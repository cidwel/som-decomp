.setcpu "65816"
.segment "CODE"
.org $62E9
map_control_0d62e9:
    .byte $E8 ; backreference distance high bits
    .byte $5D ; distance low bit/count
