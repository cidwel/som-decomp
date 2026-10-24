.setcpu "65816"
.segment "CODE"
.org $3BB9
map_control_0f3bb9:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
