.setcpu "65816"
.segment "CODE"
.org $703F
map_control_0f703f:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
