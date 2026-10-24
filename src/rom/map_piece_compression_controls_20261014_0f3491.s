.setcpu "65816"
.segment "CODE"
.org $3491
map_control_0f3491:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
