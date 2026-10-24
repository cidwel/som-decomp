.setcpu "65816"
.segment "CODE"
.org $6E27
map_control_0f6e27:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
