.setcpu "65816"
.segment "CODE"
.org $9D56
map_control_0e9d56:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
