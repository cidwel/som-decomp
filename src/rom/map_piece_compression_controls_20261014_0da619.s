.setcpu "65816"
.segment "CODE"
.org $A619
map_control_0da619:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
