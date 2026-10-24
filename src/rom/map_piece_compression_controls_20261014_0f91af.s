.setcpu "65816"
.segment "CODE"
.org $91AF
map_control_0f91af:
    .byte $D2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $07 ; distance low bit/count
