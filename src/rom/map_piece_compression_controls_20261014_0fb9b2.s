.setcpu "65816"
.segment "CODE"
.org $B9B2
map_control_0fb9b2:
    .byte $E9 ; backreference distance high bits
    .byte $D3 ; distance low bit/count
