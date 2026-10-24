.setcpu "65816"
.segment "CODE"
.org $E455
map_control_0de455:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
