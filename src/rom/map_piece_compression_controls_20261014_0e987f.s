.setcpu "65816"
.segment "CODE"
.org $987F
map_control_0e987f:
    .byte $E8 ; backreference distance high bits
    .byte $98 ; distance low bit/count
