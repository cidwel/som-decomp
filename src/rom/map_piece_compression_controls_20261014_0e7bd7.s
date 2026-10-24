.setcpu "65816"
.segment "CODE"
.org $7BD7
map_control_0e7bd7:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
