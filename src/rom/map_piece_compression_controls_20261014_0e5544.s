.setcpu "65816"
.segment "CODE"
.org $5544
map_control_0e5544:
    .byte $EE ; backreference distance high bits
    .byte $15 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
