.setcpu "65816"
.segment "CODE"
.org $2553
map_control_0e2553:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
