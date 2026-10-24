.setcpu "65816"
.segment "CODE"
.org $50E4
map_control_0c50e4:
    .byte $C2 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
