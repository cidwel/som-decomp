.setcpu "65816"
.segment "CODE"
.org $1436
map_control_0d1436:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
