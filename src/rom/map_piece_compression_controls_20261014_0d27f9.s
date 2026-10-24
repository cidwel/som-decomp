.setcpu "65816"
.segment "CODE"
.org $27F9
map_control_0d27f9:
    .byte $EA ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
