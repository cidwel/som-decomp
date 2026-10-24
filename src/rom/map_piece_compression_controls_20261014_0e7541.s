.setcpu "65816"
.segment "CODE"
.org $7541
map_control_0e7541:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
