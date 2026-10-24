.setcpu "65816"
.segment "CODE"
.org $09E4
map_control_0d09e4:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
