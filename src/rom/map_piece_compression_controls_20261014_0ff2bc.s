.setcpu "65816"
.segment "CODE"
.org $F2BC
map_control_0ff2bc:
    .byte $C5 ; same-value copy count/distance
