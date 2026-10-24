.setcpu "65816"
.segment "CODE"
.org $3FC9
map_control_0c3fc9:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
