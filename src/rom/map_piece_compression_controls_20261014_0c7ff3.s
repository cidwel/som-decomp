.setcpu "65816"
.segment "CODE"
.org $7FF3
map_control_0c7ff3:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
