.setcpu "65816"
.segment "CODE"
.org $C76F
map_control_0ec76f:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
