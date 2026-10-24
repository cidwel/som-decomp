.setcpu "65816"
.segment "CODE"
.org $5A2D
map_control_0c5a2d:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
