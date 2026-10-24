.setcpu "65816"
.segment "CODE"
.org $369F
map_control_0d369f:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
