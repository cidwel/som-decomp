.setcpu "65816"
.segment "CODE"
.org $F8BC
map_control_0ff8bc:
    .byte $D4 ; same-value copy count/distance
