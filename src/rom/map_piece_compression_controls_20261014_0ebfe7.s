.setcpu "65816"
.segment "CODE"
.org $BFE7
map_control_0ebfe7:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
