.setcpu "65816"
.segment "CODE"
.org $4D5C
map_control_0c4d5c:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
