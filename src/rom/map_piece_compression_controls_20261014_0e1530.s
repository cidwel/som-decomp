.setcpu "65816"
.segment "CODE"
.org $1530
map_control_0e1530:
    .byte $D9 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
