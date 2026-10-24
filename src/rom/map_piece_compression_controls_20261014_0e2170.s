.setcpu "65816"
.segment "CODE"
.org $2170
map_control_0e2170:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $06 ; distance low bit/count
