.setcpu "65816"
.segment "CODE"
.org $1504
map_control_0f1504:
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
