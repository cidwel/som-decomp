.setcpu "65816"
.segment "CODE"
.org $6594
map_control_0f6594:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
