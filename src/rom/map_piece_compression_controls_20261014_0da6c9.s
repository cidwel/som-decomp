.setcpu "65816"
.segment "CODE"
.org $A6C9
map_control_0da6c9:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
