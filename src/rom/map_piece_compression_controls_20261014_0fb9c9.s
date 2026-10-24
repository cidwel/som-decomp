.setcpu "65816"
.segment "CODE"
.org $B9C9
map_control_0fb9c9:
    .byte $E9 ; backreference distance high bits
    .byte $D3 ; distance low bit/count
