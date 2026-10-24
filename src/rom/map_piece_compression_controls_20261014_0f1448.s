.setcpu "65816"
.segment "CODE"
.org $1448
map_control_0f1448:
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
