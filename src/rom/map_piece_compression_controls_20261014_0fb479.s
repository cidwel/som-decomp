.setcpu "65816"
.segment "CODE"
.org $B479
map_control_0fb479:
    .byte $C7 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
