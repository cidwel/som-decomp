.setcpu "65816"
.segment "CODE"
.org $77FC
map_control_0f77fc:
    .byte $D1 ; same-value copy count/distance
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $8E ; distance low bit/count
