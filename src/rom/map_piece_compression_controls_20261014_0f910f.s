.setcpu "65816"
.segment "CODE"
.org $910F
map_control_0f910f:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $07 ; distance low bit/count
