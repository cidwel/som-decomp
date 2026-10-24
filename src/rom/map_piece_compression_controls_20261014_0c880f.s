.setcpu "65816"
.segment "CODE"
.org $880F
map_control_0c880f:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
