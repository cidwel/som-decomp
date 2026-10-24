.setcpu "65816"
.segment "CODE"
.org $6FED
map_control_0c6fed:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
