.setcpu "65816"
.segment "CODE"
.org $2D5F
map_control_0e2d5f:
    .byte $D5 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
