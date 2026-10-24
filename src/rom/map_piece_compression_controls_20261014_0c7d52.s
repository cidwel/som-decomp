.setcpu "65816"
.segment "CODE"
.org $7D52
map_control_0c7d52:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
