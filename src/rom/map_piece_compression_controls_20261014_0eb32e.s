.setcpu "65816"
.segment "CODE"
.org $B32E
map_control_0eb32e:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
