.setcpu "65816"
.segment "CODE"
.org $D4E7
map_control_0ed4e7:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
