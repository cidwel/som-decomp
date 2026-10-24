.setcpu "65816"
.segment "CODE"
.org $7BC2
map_control_0e7bc2:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
