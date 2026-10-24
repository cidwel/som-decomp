.setcpu "65816"
.segment "CODE"
.org $B50C
map_control_0eb50c:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
