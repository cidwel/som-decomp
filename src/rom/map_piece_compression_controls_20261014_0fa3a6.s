.setcpu "65816"
.segment "CODE"
.org $A3A6
map_control_0fa3a6:
    .byte $EC ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $D1 ; same-value copy count/distance
