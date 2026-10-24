.setcpu "65816"
.segment "CODE"
.org $8842
map_control_0c8842:
    .byte $C9 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
