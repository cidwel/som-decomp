.setcpu "65816"
.segment "CODE"
.org $212F
map_control_0d212f:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
