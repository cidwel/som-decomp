.setcpu "65816"
.segment "CODE"
.org $1785
map_control_0f1785:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
