.setcpu "65816"
.segment "CODE"
.org $F9EC
map_control_0ff9ec:
    .byte $C4 ; same-value copy count/distance
