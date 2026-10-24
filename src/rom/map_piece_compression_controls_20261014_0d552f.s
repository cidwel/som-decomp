.setcpu "65816"
.segment "CODE"
.org $552F
map_control_0d552f:
    .byte $C3 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
