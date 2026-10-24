.setcpu "65816"
.segment "CODE"
.org $F681
map_control_0cf681:
    .byte $D4 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
