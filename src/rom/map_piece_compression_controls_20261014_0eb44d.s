.setcpu "65816"
.segment "CODE"
.org $B44D
map_control_0eb44d:
    .byte $F1 ; progressive-copy count
    .byte $DE ; same-value copy count/distance
