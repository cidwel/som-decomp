.setcpu "65816"
.segment "CODE"
.org $B12F
map_control_0db12f:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
