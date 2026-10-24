.setcpu "65816"
.segment "CODE"
.org $1DA5
map_control_0d1da5:
    .byte $C1 ; same-value copy count/distance
    .byte $DE ; same-value copy count/distance
