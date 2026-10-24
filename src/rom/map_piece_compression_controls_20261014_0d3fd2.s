.setcpu "65816"
.segment "CODE"
.org $3FD2
map_control_0d3fd2:
    .byte $D7 ; same-value copy count/distance
    .byte $C6 ; same-value copy count/distance
