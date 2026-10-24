.setcpu "65816"
.segment "CODE"
.org $243F
map_control_0f243f:
    .byte $E8 ; backreference distance high bits
    .byte $62 ; distance low bit/count
