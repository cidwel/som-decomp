.setcpu "65816"
.segment "CODE"
.org $B103
map_control_0db103:
    .byte $CC ; same-value copy count/distance
