.setcpu "65816"
.segment "CODE"
.org $A7F9
map_control_0ea7f9:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
