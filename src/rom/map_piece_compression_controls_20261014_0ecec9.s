.setcpu "65816"
.segment "CODE"
.org $CEC9
map_control_0ecec9:
    .byte $C6 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
