.setcpu "65816"
.segment "CODE"
.org $6E38
map_control_0d6e38:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
