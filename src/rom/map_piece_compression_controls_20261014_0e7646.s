.setcpu "65816"
.segment "CODE"
.org $7646
map_control_0e7646:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
