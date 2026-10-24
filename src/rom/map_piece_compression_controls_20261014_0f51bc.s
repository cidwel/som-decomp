.setcpu "65816"
.segment "CODE"
.org $51BC
map_control_0f51bc:
    .byte $C1 ; same-value copy count/distance
