.setcpu "65816"
.segment "CODE"
.org $B91E
map_control_0eb91e:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
