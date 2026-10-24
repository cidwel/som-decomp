.setcpu "65816"
.segment "CODE"
.org $F81E
map_control_0cf81e:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
