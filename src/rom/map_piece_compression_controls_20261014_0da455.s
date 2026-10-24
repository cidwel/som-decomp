.setcpu "65816"
.segment "CODE"
.org $A455
map_control_0da455:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
