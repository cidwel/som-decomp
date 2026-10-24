.setcpu "65816"
.segment "CODE"
.org $41E8
map_control_0e41e8:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
