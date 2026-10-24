.setcpu "65816"
.segment "CODE"
.org $6D38
map_control_0c6d38:
    .byte $D7 ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
