.setcpu "65816"
.segment "CODE"
.org $A453
map_control_0fa453:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
