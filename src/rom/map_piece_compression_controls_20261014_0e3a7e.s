.setcpu "65816"
.segment "CODE"
.org $3A7E
map_control_0e3a7e:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
