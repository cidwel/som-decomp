.setcpu "65816"
.segment "CODE"
.org $92CC
map_control_0f92cc:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
