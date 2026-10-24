.setcpu "65816"
.segment "CODE"
.org $D981
map_control_0dd981:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
