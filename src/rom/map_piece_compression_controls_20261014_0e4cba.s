.setcpu "65816"
.segment "CODE"
.org $4CBA
map_control_0e4cba:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
