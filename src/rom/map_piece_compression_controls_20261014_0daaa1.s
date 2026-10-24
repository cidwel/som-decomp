.setcpu "65816"
.segment "CODE"
.org $AAA1
map_control_0daaa1:
    .byte $C3 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
