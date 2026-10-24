.setcpu "65816"
.segment "CODE"
.org $11C2
map_control_0e11c2:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
