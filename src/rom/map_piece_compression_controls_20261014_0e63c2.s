.setcpu "65816"
.segment "CODE"
.org $63C2
map_control_0e63c2:
    .byte $C9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
