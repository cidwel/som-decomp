.setcpu "65816"
.segment "CODE"
.org $2D5A
map_control_0e2d5a:
    .byte $D5 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
