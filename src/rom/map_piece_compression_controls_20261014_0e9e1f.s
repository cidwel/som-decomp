.setcpu "65816"
.segment "CODE"
.org $9E1F
map_control_0e9e1f:
    .byte $E8 ; backreference distance high bits
    .byte $94 ; distance low bit/count
