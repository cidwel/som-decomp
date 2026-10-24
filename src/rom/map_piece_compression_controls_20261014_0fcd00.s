.setcpu "65816"
.segment "CODE"
.org $CD00
map_control_0fcd00:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
