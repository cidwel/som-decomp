.setcpu "65816"
.segment "CODE"
.org $2D64
map_control_0e2d64:
    .byte $D5 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
