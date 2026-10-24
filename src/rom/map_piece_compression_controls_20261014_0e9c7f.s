.setcpu "65816"
.segment "CODE"
.org $9C7F
map_control_0e9c7f:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
