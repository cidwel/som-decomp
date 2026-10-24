.setcpu "65816"
.segment "CODE"
.org $84BF
map_control_0f84bf:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
