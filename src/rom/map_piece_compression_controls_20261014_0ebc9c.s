.setcpu "65816"
.segment "CODE"
.org $BC9C
map_control_0ebc9c:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
