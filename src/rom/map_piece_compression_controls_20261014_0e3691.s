.setcpu "65816"
.segment "CODE"
.org $3691
map_control_0e3691:
    .byte $C1 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
