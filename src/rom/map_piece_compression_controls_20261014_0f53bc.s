.setcpu "65816"
.segment "CODE"
.org $53BC
map_control_0f53bc:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
