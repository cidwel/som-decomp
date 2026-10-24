.setcpu "65816"
.segment "CODE"
.org $073B
map_control_0e073b:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
