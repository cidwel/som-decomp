.setcpu "65816"
.segment "CODE"
.org $1647
map_control_0f1647:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
