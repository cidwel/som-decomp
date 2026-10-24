.setcpu "65816"
.segment "CODE"
.org $4C7D
map_control_0c4c7d:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
