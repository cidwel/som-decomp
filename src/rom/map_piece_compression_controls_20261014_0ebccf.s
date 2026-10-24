.setcpu "65816"
.segment "CODE"
.org $BCCF
map_control_0ebccf:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
