.setcpu "65816"
.segment "CODE"
.org $7C92
map_control_0d7c92:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
