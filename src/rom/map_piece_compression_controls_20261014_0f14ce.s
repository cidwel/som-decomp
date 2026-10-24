.setcpu "65816"
.segment "CODE"
.org $14CE
map_control_0f14ce:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
