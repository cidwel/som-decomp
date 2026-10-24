.setcpu "65816"
.segment "CODE"
.org $5263
map_control_0d5263:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
