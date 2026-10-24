.setcpu "65816"
.segment "CODE"
.org $B7D4
map_control_0eb7d4:
    .byte $EE ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
