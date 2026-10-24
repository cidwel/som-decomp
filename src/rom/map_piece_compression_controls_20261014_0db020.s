.setcpu "65816"
.segment "CODE"
.org $B020
map_control_0db020:
    .byte $D2 ; same-value copy count/distance
