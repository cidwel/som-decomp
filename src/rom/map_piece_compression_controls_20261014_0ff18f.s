.setcpu "65816"
.segment "CODE"
.org $F18F
map_control_0ff18f:
    .byte $E8 ; backreference distance high bits
    .byte $3E ; distance low bit/count
