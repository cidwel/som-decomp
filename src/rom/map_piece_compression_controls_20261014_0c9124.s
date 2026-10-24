.setcpu "65816"
.segment "CODE"
.org $9124
map_control_0c9124:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
