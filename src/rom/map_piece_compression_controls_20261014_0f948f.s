.setcpu "65816"
.segment "CODE"
.org $948F
map_control_0f948f:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
