.setcpu "65816"
.segment "CODE"
.org $BFD9
map_control_0ebfd9:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
