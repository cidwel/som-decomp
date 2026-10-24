.setcpu "65816"
.segment "CODE"
.org $77EF
map_control_0c77ef:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
