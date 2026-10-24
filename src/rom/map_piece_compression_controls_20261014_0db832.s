.setcpu "65816"
.segment "CODE"
.org $B832
map_control_0db832:
    .byte $C5 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
