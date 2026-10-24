.setcpu "65816"
.segment "CODE"
.org $7528
map_control_0e7528:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
