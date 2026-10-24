.setcpu "65816"
.segment "CODE"
.org $2269
map_control_0e2269:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
