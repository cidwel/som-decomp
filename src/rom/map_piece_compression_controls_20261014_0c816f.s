.setcpu "65816"
.segment "CODE"
.org $816F
map_control_0c816f:
    .byte $E9 ; backreference distance high bits
    .byte $8B ; distance low bit/count
