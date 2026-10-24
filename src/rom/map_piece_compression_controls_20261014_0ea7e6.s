.setcpu "65816"
.segment "CODE"
.org $A7E6
map_control_0ea7e6:
    .byte $CD ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
