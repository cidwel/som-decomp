.setcpu "65816"
.segment "CODE"
.org $D88A
map_control_0dd88a:
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
