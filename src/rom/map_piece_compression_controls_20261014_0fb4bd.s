.setcpu "65816"
.segment "CODE"
.org $B4BD
map_control_0fb4bd:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
