.setcpu "65816"
.segment "CODE"
.org $F5F6
map_control_0ef5f6:
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
