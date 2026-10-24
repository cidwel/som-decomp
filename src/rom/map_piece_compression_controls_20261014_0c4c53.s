.setcpu "65816"
.segment "CODE"
.org $4C53
map_control_0c4c53:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
