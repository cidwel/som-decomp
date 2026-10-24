.setcpu "65816"
.segment "CODE"
.org $C9CC
map_control_0fc9cc:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
