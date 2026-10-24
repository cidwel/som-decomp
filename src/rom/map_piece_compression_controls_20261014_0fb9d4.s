.setcpu "65816"
.segment "CODE"
.org $B9D4
map_control_0fb9d4:
    .byte $E9 ; backreference distance high bits
    .byte $D3 ; distance low bit/count
