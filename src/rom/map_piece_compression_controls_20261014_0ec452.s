.setcpu "65816"
.segment "CODE"
.org $C452
map_control_0ec452:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
