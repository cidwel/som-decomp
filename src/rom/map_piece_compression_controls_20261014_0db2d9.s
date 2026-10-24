.setcpu "65816"
.segment "CODE"
.org $B2D9
map_control_0db2d9:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
