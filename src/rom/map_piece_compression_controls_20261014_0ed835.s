.setcpu "65816"
.segment "CODE"
.org $D835
map_control_0ed835:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
