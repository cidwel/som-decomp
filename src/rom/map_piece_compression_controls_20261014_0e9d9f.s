.setcpu "65816"
.segment "CODE"
.org $9D9F
map_control_0e9d9f:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
