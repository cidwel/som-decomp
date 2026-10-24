.setcpu "65816"
.segment "CODE"
.org $109C
map_control_0e109c:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
