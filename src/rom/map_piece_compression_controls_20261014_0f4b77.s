.setcpu "65816"
.segment "CODE"
.org $4B77
map_control_0f4b77:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
