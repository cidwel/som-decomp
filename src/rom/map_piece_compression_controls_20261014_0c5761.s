.setcpu "65816"
.segment "CODE"
.org $5761
map_control_0c5761:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
