.setcpu "65816"
.segment "CODE"
.org $CAC3
map_control_0fcac3:
    .byte $C2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $8D ; distance low bit/count
