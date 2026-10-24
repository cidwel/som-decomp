.setcpu "65816"
.segment "CODE"
.org $3C0C
map_control_0e3c0c:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
