.setcpu "65816"
.segment "CODE"
.org $F04C
map_control_0ef04c:
    .byte $D7 ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
