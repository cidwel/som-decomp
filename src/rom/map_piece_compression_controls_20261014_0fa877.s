.setcpu "65816"
.segment "CODE"
.org $A877
map_control_0fa877:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
