.setcpu "65816"
.segment "CODE"
.org $9D6F
map_control_0e9d6f:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
