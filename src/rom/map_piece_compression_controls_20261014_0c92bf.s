.setcpu "65816"
.segment "CODE"
.org $92BF
map_control_0c92bf:
    .byte $C4 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
