.setcpu "65816"
.segment "CODE"
.org $9B43
map_control_0d9b43:
    .byte $E8 ; backreference distance high bits
    .byte $98 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
