.setcpu "65816"
.segment "CODE"
.org $8A22
map_control_0d8a22:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
