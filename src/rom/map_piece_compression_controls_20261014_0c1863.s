.setcpu "65816"
.segment "CODE"
.org $1863
map_control_0c1863:
    .byte $EE ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
