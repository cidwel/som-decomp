.setcpu "65816"
.segment "CODE"
.org $B9A5
map_control_0fb9a5:
    .byte $E9 ; backreference distance high bits
    .byte $D3 ; distance low bit/count
