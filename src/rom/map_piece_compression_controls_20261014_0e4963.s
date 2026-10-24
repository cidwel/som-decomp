.setcpu "65816"
.segment "CODE"
.org $4963
map_control_0e4963:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $DF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
