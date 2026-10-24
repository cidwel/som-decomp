.setcpu "65816"
.segment "CODE"
.org $4DD7
map_control_0e4dd7:
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
