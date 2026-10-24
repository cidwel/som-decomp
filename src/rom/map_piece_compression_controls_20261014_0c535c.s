.setcpu "65816"
.segment "CODE"
.org $535C
map_control_0c535c:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
