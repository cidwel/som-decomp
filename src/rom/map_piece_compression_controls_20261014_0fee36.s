.setcpu "65816"
.segment "CODE"
.org $EE36
map_control_0fee36:
    .byte $C6 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
