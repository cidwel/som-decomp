.setcpu "65816"
.segment "CODE"
.org $4E48
map_control_0d4e48:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
