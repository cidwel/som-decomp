.setcpu "65816"
.segment "CODE"
.org $671E
map_control_0f671e:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $CC ; same-value copy count/distance
