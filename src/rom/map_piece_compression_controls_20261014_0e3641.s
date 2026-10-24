.setcpu "65816"
.segment "CODE"
.org $3641
map_control_0e3641:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
