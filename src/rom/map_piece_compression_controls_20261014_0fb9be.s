.setcpu "65816"
.segment "CODE"
.org $B9BE
map_control_0fb9be:
    .byte $E9 ; backreference distance high bits
    .byte $D3 ; distance low bit/count
