.setcpu "65816"
.segment "CODE"
.org $9B70
map_control_0e9b70:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
