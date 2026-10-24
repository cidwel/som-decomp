.setcpu "65816"
.segment "CODE"
.org $C8D8
map_control_0ec8d8:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
