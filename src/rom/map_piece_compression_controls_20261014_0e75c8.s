.setcpu "65816"
.segment "CODE"
.org $75C8
map_control_0e75c8:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
