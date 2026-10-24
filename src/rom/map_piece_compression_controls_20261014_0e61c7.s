.setcpu "65816"
.segment "CODE"
.org $61C7
map_control_0e61c7:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
