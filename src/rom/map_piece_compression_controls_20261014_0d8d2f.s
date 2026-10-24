.setcpu "65816"
.segment "CODE"
.org $8D2F
map_control_0d8d2f:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
