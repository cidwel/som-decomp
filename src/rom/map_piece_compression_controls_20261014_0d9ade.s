.setcpu "65816"
.segment "CODE"
.org $9ADE
map_control_0d9ade:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
