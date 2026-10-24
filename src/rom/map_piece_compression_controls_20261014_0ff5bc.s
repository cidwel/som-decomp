.setcpu "65816"
.segment "CODE"
.org $F5BC
map_control_0ff5bc:
    .byte $C3 ; same-value copy count/distance
