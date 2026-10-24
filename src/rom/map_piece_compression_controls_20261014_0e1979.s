.setcpu "65816"
.segment "CODE"
.org $1979
map_control_0e1979:
    .byte $CA ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
