.setcpu "65816"
.segment "CODE"
.org $6D0E
map_control_0c6d0e:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
