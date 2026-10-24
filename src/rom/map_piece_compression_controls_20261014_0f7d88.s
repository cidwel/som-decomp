.setcpu "65816"
.segment "CODE"
.org $7D88
map_control_0f7d88:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
