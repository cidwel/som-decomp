.setcpu "65816"
.segment "CODE"
.org $A87B
map_control_0da87b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
