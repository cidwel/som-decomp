.setcpu "65816"
.segment "CODE"
.org $E6E3
map_control_0fe6e3:
    .byte $C6 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
