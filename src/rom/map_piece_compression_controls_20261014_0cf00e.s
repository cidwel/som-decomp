.setcpu "65816"
.segment "CODE"
.org $F00E
map_control_0cf00e:
    .byte $C3 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
