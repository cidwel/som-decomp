.setcpu "65816"
.segment "CODE"
.org $31E0
map_control_0e31e0:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
