.setcpu "65816"
.segment "CODE"
.org $6E1F
map_control_0d6e1f:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
