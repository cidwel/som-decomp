.setcpu "65816"
.segment "CODE"
.org $1395
map_control_0e1395:
    .byte $EF ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
