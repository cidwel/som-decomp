.setcpu "65816"
.segment "CODE"
.org $9A33
map_control_0d9a33:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
