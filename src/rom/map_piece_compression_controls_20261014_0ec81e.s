.setcpu "65816"
.segment "CODE"
.org $C81E
map_control_0ec81e:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
