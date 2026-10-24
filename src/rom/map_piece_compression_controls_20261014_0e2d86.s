.setcpu "65816"
.segment "CODE"
.org $2D86
map_control_0e2d86:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
