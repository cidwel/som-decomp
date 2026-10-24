.setcpu "65816"
.segment "CODE"
.org $B458
map_control_0db458:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
