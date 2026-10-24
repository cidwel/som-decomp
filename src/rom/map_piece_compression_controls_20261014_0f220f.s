.setcpu "65816"
.segment "CODE"
.org $220F
map_control_0f220f:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
