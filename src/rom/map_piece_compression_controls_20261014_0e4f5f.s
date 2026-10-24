.setcpu "65816"
.segment "CODE"
.org $4F5F
map_control_0e4f5f:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
