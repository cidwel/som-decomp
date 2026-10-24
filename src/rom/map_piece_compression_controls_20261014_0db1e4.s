.setcpu "65816"
.segment "CODE"
.org $B1E4
map_control_0db1e4:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
